// Fizzbuzz implemented with simple accumulators
//
// SPDX-License-Identifier: GPL-2.0-only
    .text
    .globl  main
    .type   main, @function

fizz_s:
	.string	"fizz"
buzz_s:
	.string	"buzz"
int_s:
        .string "%i"
nl_s:
        .string "\n"

main:
    mov $1, %rbx
    mov $3, %r12
    mov $5, %r13

loop:
    mov $0, %r14

    cmp %rbx, %r12
    jne check_buzz

    add $3, %r12

    lea fizz_s(%rip), %rdi
    xor %eax, %eax 
    call printf
    inc %r14

check_buzz:
    cmp %rbx, %r13
    jne print_num

    add $5, %r13

    lea buzz_s(%rip), %rdi
    xor %eax, %eax 
    call printf
    inc %r14

print_num:
    test %r14, %r14
    jne next

    lea int_s(%rip), %rdi
    mov %rbx, %rsi 
    xor %eax, %eax 
    call printf

next:
    lea nl_s(%rip), %rdi
    xor %eax, %eax 
    call printf

    inc %rbx
    cmp $101, %rbx
    jne loop

out:
    xor %eax, %eax
    ret



    .section    .note.GNU-stack,"",@progbits
