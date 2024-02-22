    .text
    .globl  main
    .type   main, @function

fizzbuzz_s:
	.string	"fizzbuzz\n"
fizz_s:
	.string	"fizz\n"
buzz_s:
	.string	"buzz\n"
int_s:
        .string "%i\n"

main:
    mov $1, %rbx

    mov $3, %r12
    mov $5, %r13

loop:
    lea int_s(%rip), %rdi
    mov %rbx, %rsi 
    xor %eax, %eax 
    mov $1, %r8
    mov $2, %r9

    // check fizz
    lea fizz_s(%rip), %r14
    mov $3, %r15
    add %r12, %r15

    cmp %rbx, %r12
    cmove %r14, %rdi
    cmove %r15, %r12
    cmove %rax, %r8

    // check buzz
    lea buzz_s(%rip), %r14
    mov $5, %r15
    add %r13, %r15

    cmp %rbx, %r13
    cmove %r14, %rdi
    cmove %r15, %r13
    cmove %rax, %r9

    // check fizzbuzz
    lea fizzbuzz_s(%rip), %r14
    cmp %r8, %r9
    cmove %r14, %rdi 

    call printf

    mov $2, %ecx
    inc %rbx
    cmp $101, %rbx
    loopne loop

out:
    xor %eax, %eax
    ret



    .section    .note.GNU-stack,"",@progbits
