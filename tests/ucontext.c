
#ifndef __x86_64__
#error "This only works for x86-64"
#endif

#include <elf.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/procfs.h>
#include <ucontext.h>
#include <unistd.h>

#include <cpu-register-definitions/linux-x86-64-elf-ucontext.h>
#include <cpu-register-definitions/linux-x86-64-ucontext.h>

static ucontext_t U;
static jmp_buf J;

static void handler(int sig, siginfo_t *info, void *context) {
  ucontext_t *ucontext = context;
  memcpy(&U, ucontext, sizeof(ucontext_t));
  longjmp(J, 1);
}

int main(int argc, const char **argv) {
  struct sigaction sigact;

  sigact.sa_sigaction = handler;
  sigact.sa_flags = SA_SIGINFO;
  sigemptyset(&sigact.sa_mask);
  sigaction(SIGILL, &sigact, NULL);

  if (setjmp(J) == 0) {
    asm volatile("\n\tmov $1, %%rax"
                 "\n\tmov $2, %%rbx"
                 "\n\tmov $3, %%rcx"
                 "\n\tmov $4, %%rdx"
                 "\n\tmov $5, %%rsi"
                 "\n\tmov $6, %%rdi"
                 "\n\tmov $7, %%rbp"
                 "\n\tmov $8, %%r8"
                 "\n\tmov $9, %%r9"
                 "\n\tmov $10, %%r10"
                 "\n\tmov $11, %%r11"
                 "\n\tmov $12, %%r12"
                 "\n\tmov $13, %%r13"
                 "\n\tmov $14, %%r14"
                 "\n\tmov $15, %%r15"
                 "\n\tud2"
                 :
                 :
                 :);
    abort();
  }

#ifdef DUMP_AS_TEXT
  for (int i = 0; i < REG_X86_64_UCONTEXT_GREGSET_COUNT; i++) {
    printf("%3s: %016llx\n", reg_x86_64_ucontext_gregset_name(i),
           U.uc_mcontext.gregs[i]);
  }
#endif

#ifdef DUMP_AS_ELFCORE
  {

    Elf64_Nhdr nhdr = {
        .n_namesz = 5,
        .n_descsz = sizeof(prstatus_t),
        .n_type = NT_PRSTATUS,
    };

    prstatus_t prstatus = {
        .pr_pid = 1337,
    };

    /* Everything around above and below this line is just
     * scaffolding to test this one line. */
    x86_64_gpregs_elfgregs_from_ucontext(prstatus.pr_reg, U.uc_mcontext.gregs);

    Elf64_Ehdr ehdr = {
        .e_ident[EI_MAG0] = ELFMAG0,
        .e_ident[EI_MAG1] = ELFMAG1,
        .e_ident[EI_MAG2] = ELFMAG2,
        .e_ident[EI_MAG3] = ELFMAG3,
        .e_ident[EI_CLASS] = ELFCLASS64,
        .e_ident[EI_DATA] = ELFDATA2LSB,
        .e_ident[EI_VERSION] = EV_CURRENT,
        .e_ident[EI_OSABI] = ELFOSABI_NONE,
        .e_type = ET_CORE,
        .e_machine = EM_X86_64,
        .e_version = EV_CURRENT,
        .e_phoff = sizeof(Elf64_Ehdr),
        .e_ehsize = sizeof(Elf64_Ehdr),
        .e_phentsize = sizeof(Elf64_Phdr),
        .e_phnum = 1,
    };

    Elf64_Phdr phdr = {
        .p_type = PT_NOTE,
        .p_offset = sizeof(Elf64_Ehdr) + sizeof(Elf64_Phdr),
        .p_filesz = sizeof(nhdr) + 8 + sizeof(prstatus),
    };

    write(STDOUT_FILENO, &ehdr, sizeof(ehdr));
    write(STDOUT_FILENO, &phdr, sizeof(phdr));
    write(STDOUT_FILENO, &nhdr, sizeof(nhdr));
    write(STDOUT_FILENO, "CORE\0\0\0\0", 8);
    write(STDOUT_FILENO, &prstatus, sizeof(prstatus));
  }
#endif

  return 0;
}
