// Fizzbuzz implemented using division remainders
//
// SPDX-License-Identifier: GPL-2.0-only
    .text
    .globl  main
    .type   main, @function

fizzbuzz_s:
    .string "fizzbuzz\n"
fizz_s:
    .string "fizz\n"
buzz_s:
    .string "buzz\n"
int_s:
    .string "%i\n"

main:
    mov $1, %rbx
    mov $3, %r12
    mov $5, %r13

loop:
    // assume we just print the number
    lea int_s(%rip), %rdi
    mov %rbx, %rsi 
  
    xor %r14, %r14

    mov %rbx, %rax
    xor %rdx, %rdx
    div %r12
    test %rdx, %rdx
    jnz check_buzz

    lea fizz_s(%rip), %rdi
    inc %r14

check_buzz:
    mov %rbx, %rax
    xor %rdx, %rdx
    div %r13
    test %rdx, %rdx
    jnz print_it

    test %r14, %r14
    jz just_buzz
    lea fizzbuzz_s(%rip), %rdi
    jmp print_it

just_buzz:
    lea buzz_s(%rip), %rdi

print_it:
    xor %eax, %eax 
    call printf

next:
    inc %rbx
    cmp $101, %rbx
    jne loop

out:
    xor %eax, %eax
    ret



    .section    .note.GNU-stack,"",@progbits
