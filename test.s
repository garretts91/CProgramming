.global _start
.intel_syntax noprefix

_start:
    move rax, 60
    move rdi, 69
    syscall 