    # Program File: Print_Integer.asm
    # Author: <REDACTED>
    # Purpose: Print an Integer

.data

.text
addi    $t0,    $zero,  10  # load constant 10 into $t0 by adding it with 0 $zero
addi    $t1,    $zero,  4   # load constant 4 into $t1 by adding it with 0 $zero

mul     $t2,    $t0,    $t1 # multiply $t0 and $t1 and stored result into $t2

li      $v0,    1           # load $v0 for integer printing

add     $a0,    $zero,  $t2 # load $t2 into $a0 by adding $t2 and 0 $zero

syscall                     # print integer call

li      $v0,    10          # load exit flag into $v0
syscall                     # exit the program