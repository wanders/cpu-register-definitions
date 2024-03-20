CPU REGISTER DEFINITIONS
========================

(at least on x86-64) The registers you get gregset_t which you get in
ucontext when using a signal handler with SA_SIGINFO have a different
ordering than the registers in a prstatus_t which is used in ELF core
files.

To avoid someone else having to go through the pain in converting
between these, here is code for that (just make a copy of grab the
includes in cpu-register-definitions/ directory).
