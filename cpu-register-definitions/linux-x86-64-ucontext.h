#ifndef CPU_REGDEFS_LINUX_X86_64_UCONTEXT_H
#define CPU_REGDEFS_LINUX_X86_64_UCONTEXT_H 1

/**
 * Indices into gregset_t (defined in ucontext.h) which is what one
 * would get in context->uc_mcontext.gregs in getcontext or a signal
 * handler set up with SA_SIGINFO.
 */
enum reg_x86_64_ucontext_gregset {
	REG_X86_64_UCONTEXT_GREGSET_R8,
	REG_X86_64_UCONTEXT_GREGSET_R9,
	REG_X86_64_UCONTEXT_GREGSET_R10,
	REG_X86_64_UCONTEXT_GREGSET_R11,
	REG_X86_64_UCONTEXT_GREGSET_R12,
	REG_X86_64_UCONTEXT_GREGSET_R13,
	REG_X86_64_UCONTEXT_GREGSET_R14,
	REG_X86_64_UCONTEXT_GREGSET_R15,
	REG_X86_64_UCONTEXT_GREGSET_RDI,
	REG_X86_64_UCONTEXT_GREGSET_RSI,
	REG_X86_64_UCONTEXT_GREGSET_RBP,
	REG_X86_64_UCONTEXT_GREGSET_RBX,
	REG_X86_64_UCONTEXT_GREGSET_RDX,
	REG_X86_64_UCONTEXT_GREGSET_RAX,
	REG_X86_64_UCONTEXT_GREGSET_RCX,
	REG_X86_64_UCONTEXT_GREGSET_RSP,
	REG_X86_64_UCONTEXT_GREGSET_RIP,
	REG_X86_64_UCONTEXT_GREGSET_EFLAGS,
	REG_X86_64_UCONTEXT_GREGSET_CSGSFS,
	REG_X86_64_UCONTEXT_GREGSET_ERR,
	REG_X86_64_UCONTEXT_GREGSET_TRAPNO,
	REG_X86_64_UCONTEXT_GREGSET_OLDMASK,
	REG_X86_64_UCONTEXT_GREGSET_CR2,
	REG_X86_64_UCONTEXT_GREGSET_LAST = REG_X86_64_UCONTEXT_GREGSET_CR2
};

#define REG_X86_64_UCONTEXT_GREGSET_COUNT (REG_X86_64_UCONTEXT_GREGSET_LAST + 1)

static inline const char *
reg_x86_64_ucontext_gregset_name (enum reg_x86_64_ucontext_gregset r)
{
	switch (r) {
		case REG_X86_64_UCONTEXT_GREGSET_R8:
			return "r8";
		case REG_X86_64_UCONTEXT_GREGSET_R9:
			return "r9";
		case REG_X86_64_UCONTEXT_GREGSET_R10:
			return "r10";
		case REG_X86_64_UCONTEXT_GREGSET_R11:
			return "r11";
		case REG_X86_64_UCONTEXT_GREGSET_R12:
			return "r12";
		case REG_X86_64_UCONTEXT_GREGSET_R13:
			return "r13";
		case REG_X86_64_UCONTEXT_GREGSET_R14:
			return "r14";
		case REG_X86_64_UCONTEXT_GREGSET_R15:
			return "r15";
		case REG_X86_64_UCONTEXT_GREGSET_RDI:
			return "rdi";
		case REG_X86_64_UCONTEXT_GREGSET_RSI:
			return "rsi";
		case REG_X86_64_UCONTEXT_GREGSET_RBP:
			return "rbp";
		case REG_X86_64_UCONTEXT_GREGSET_RBX:
			return "rbx";
		case REG_X86_64_UCONTEXT_GREGSET_RDX:
			return "rdx";
		case REG_X86_64_UCONTEXT_GREGSET_RAX:
			return "rax";
		case REG_X86_64_UCONTEXT_GREGSET_RCX:
			return "rcx";
		case REG_X86_64_UCONTEXT_GREGSET_RSP:
			return "rsp";
		case REG_X86_64_UCONTEXT_GREGSET_RIP:
			return "rip";
		case REG_X86_64_UCONTEXT_GREGSET_EFLAGS:
			return "eflags";
		case REG_X86_64_UCONTEXT_GREGSET_CSGSFS:
			return "csgsfs";
		case REG_X86_64_UCONTEXT_GREGSET_ERR:
			return "err";
		case REG_X86_64_UCONTEXT_GREGSET_TRAPNO:
			return "trapno";
		case REG_X86_64_UCONTEXT_GREGSET_OLDMASK:
			return "oldmask";
		case REG_X86_64_UCONTEXT_GREGSET_CR2:
			return "cr2";
	}
	return "UNKNOWN";
}

#endif
