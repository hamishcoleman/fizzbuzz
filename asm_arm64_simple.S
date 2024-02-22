// Fizzbuzz implemented with simple accumulators and no division
//
// SPDX-License-Identifier: GPL-2.0-only
    .text

fizz_s:
    .string "fizz"
buzz_s:
    .string "buzz"
int_s:
    .string "%i"
nl_s:
    .string "\n"

    .align 2
    .globl  main
    .type   main, @function
main:
    .cfi_startproc
    stp x29, x30, [sp, -48]!
    .cfi_def_cfa_offset 48
    .cfi_offset 29, -48
    .cfi_offset 30, -40
    mov x29, sp

    mov x19, 1
    mov x20, 3
    mov x21, 5

loop:
    mov x22, 0

    cmp x19, x20
    bne check_buzz

    add x20, x20, 3

    adrp x0, fizz_s
    add x0, x0, :lo12:fizz_s
    bl printf
    add x22, x22, 1

check_buzz:
    cmp x19, x21
    bne print_num

    add x21, x21, 5

    adrp x0, buzz_s
    add x0, x0, :lo12:buzz_s
    bl printf
    add x22, x22, 1

print_num:
    cmp x22, 0
    bne next

    adrp x0, int_s
    add x0, x0, :lo12:int_s
    mov x1, x19
    bl printf

next:
    adrp x0, nl_s
    add x0, x0, :lo12:nl_s
    bl printf

    add x19, x19, 1
    cmp x19, 101
    blt loop

out:
    mov x0, 0
    ldp x29, x30, [sp], 48
    .cfi_restore 30
    .cfi_restore 29
    .cfi_def_cfa_offset 0
    ret
    .cfi_endproc


    .section    .note.GNU-stack,"",@progbits
