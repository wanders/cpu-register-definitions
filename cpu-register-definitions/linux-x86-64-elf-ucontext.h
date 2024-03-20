#ifndef CPU_REGDEFS_LINUX_X86_64_ELF_UCONTEXT_H
#define CPU_REGDEFS_LINUX_X86_64_ELF_UCONTEXT_H 1

#include "linux-x86-64-elf.h"
#include "linux-x86-64-ucontext.h"

static inline void
x86_64_gpregs_elfgregs_from_ucontext (unsigned long long elf_gregs[static REG_X86_64_ELF_GREGSET_COUNT], const long long ucontext_gregset[static REG_X86_64_UCONTEXT_GREGSET_COUNT])
{
	elf_gregs[REG_X86_64_ELF_GREGSET_RAX] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RAX];
	elf_gregs[REG_X86_64_ELF_GREGSET_RBX] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RBX];
	elf_gregs[REG_X86_64_ELF_GREGSET_RCX] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RCX];
	elf_gregs[REG_X86_64_ELF_GREGSET_RDX] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RDX];
	elf_gregs[REG_X86_64_ELF_GREGSET_RSI] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RSI];
	elf_gregs[REG_X86_64_ELF_GREGSET_RDI] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RDI];
	elf_gregs[REG_X86_64_ELF_GREGSET_RBP] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RBP];
	elf_gregs[REG_X86_64_ELF_GREGSET_RSP] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RSP];
	elf_gregs[REG_X86_64_ELF_GREGSET_R8] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R8];
	elf_gregs[REG_X86_64_ELF_GREGSET_R9] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R9];
	elf_gregs[REG_X86_64_ELF_GREGSET_R10] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R10];
	elf_gregs[REG_X86_64_ELF_GREGSET_R11] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R11];
	elf_gregs[REG_X86_64_ELF_GREGSET_R12] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R12];
	elf_gregs[REG_X86_64_ELF_GREGSET_R13] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R13];
	elf_gregs[REG_X86_64_ELF_GREGSET_R14] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R14];
	elf_gregs[REG_X86_64_ELF_GREGSET_R15] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_R15];
	elf_gregs[REG_X86_64_ELF_GREGSET_RIP] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_RIP];
	elf_gregs[REG_X86_64_ELF_GREGSET_EFLAGS] = ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_EFLAGS];

	elf_gregs[REG_X86_64_ELF_GREGSET_CS] = (ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_CSGSFS] >> 32) & 0xffff;
	elf_gregs[REG_X86_64_ELF_GREGSET_GS] = (ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_CSGSFS] >> 16) & 0xffff;
	elf_gregs[REG_X86_64_ELF_GREGSET_FS] = (ucontext_gregset[REG_X86_64_UCONTEXT_GREGSET_CSGSFS] >> 0) & 0xffff;
}

#endif
