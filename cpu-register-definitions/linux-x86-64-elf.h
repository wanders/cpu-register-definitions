#ifndef CPU_REGDEFS_LINUX_X86_64_ELF_H
#define CPU_REGDEFS_LINUX_X86_64_ELF_H 1

/**
 * Indices into elf_gregset_t array (defined in bits/procfs.h) which
 * is what one would see in a coredump's NT_PRSTATUS note's
 * prstatus_t::pr_reg
 *
 * It might be worth nothing that this is an array with same order as
 * the elements in struct user_regs_struct defined in sys/user.h.
 */
enum {
	REG_X86_64_ELF_GREGSET_R15,
	REG_X86_64_ELF_GREGSET_R14,
	REG_X86_64_ELF_GREGSET_R13,
	REG_X86_64_ELF_GREGSET_R12,
	REG_X86_64_ELF_GREGSET_RBP,
	REG_X86_64_ELF_GREGSET_RBX,
	REG_X86_64_ELF_GREGSET_R11,
	REG_X86_64_ELF_GREGSET_R10,
	REG_X86_64_ELF_GREGSET_R9,
	REG_X86_64_ELF_GREGSET_R8,
	REG_X86_64_ELF_GREGSET_RAX,
	REG_X86_64_ELF_GREGSET_RCX,
	REG_X86_64_ELF_GREGSET_RDX,
	REG_X86_64_ELF_GREGSET_RSI,
	REG_X86_64_ELF_GREGSET_RDI,
	REG_X86_64_ELF_GREGSET_ORIG_RAX,
	REG_X86_64_ELF_GREGSET_RIP,
	REG_X86_64_ELF_GREGSET_CS,
	REG_X86_64_ELF_GREGSET_EFLAGS,
	REG_X86_64_ELF_GREGSET_RSP,
	REG_X86_64_ELF_GREGSET_SS,
	REG_X86_64_ELF_GREGSET_FS_BASE,
	REG_X86_64_ELF_GREGSET_GS_BASE,
	REG_X86_64_ELF_GREGSET_DS,
	REG_X86_64_ELF_GREGSET_ES,
	REG_X86_64_ELF_GREGSET_FS,
	REG_X86_64_ELF_GREGSET_GS,
	REG_X86_64_ELF_GREGSET_LAST = REG_X86_64_ELF_GREGSET_GS
};

#define REG_X86_64_ELF_GREGSET_COUNT (REG_X86_64_ELF_GREGSET_LAST + 1)

#endif

