.data   
promtA: .asciiz "Enter A: "
promtB: .asciiz "Enter B: "
promtC: .asciiz "Enter C: "
promtx: .asciiz "Enter x: "
ans:    .asciiz "Answer : "
endl:   .asciiz "\n"


.text   
main:   
    la      $a0,    promtA      # load promptA into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string promtA

    li      $v0,    5           # load integer scan falg into $v0
    syscall                     # read the input and stored into $v0
    move    $t1,    $v0         # move scanned input $v0 into $t1

    la      $a0,    promtB      # load promptB into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string promtB

    li      $v0,    5           # load integer scan falg into $v0
    syscall                     # read the input and stored into $v0
    move    $t2,    $v0         # move scanned input $v0 into $t2

    la      $a0,    promtC      # load promptC into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string promtC

    li      $v0,    5           # load integer scan falg into $v0
    syscall                     # read the input and stored into $v0
    move    $t3,    $v0         # move scanned input $v0 into $t3

    la      $a0,    promtx      # load promptx into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string promtx

    li      $v0,    5           # load integer scan falg into $v0
    syscall                     # read the input and stored into $v0
    move    $t0,    $v0         # move scanned input $v0 into $t0

    mul     $t4,    $t0,    $t0 # multiply x * x ($t0 * $t0) and store in $t4
    mul     $t5,    $t4,    $t1 # multiply x^2 * A ($t4 * $t1) and store in $t5
    mul     $t2,    $t2,    $t0 # multiply x * B ($t0 * $t2) and store in $t2
    add     $t0,    $t5,    $t2 # Add Ax^2 + Bx ($t5, $t2) and store in $t0
    add     $t0,    $t0,    $t3 # Add C + Ax^2 + Bx ($t0, $t3) and stored into $t0

    la      $a0,    ans         # load ans into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string ans

    move    $a0,    $t0         # move calculation result ($t0) into $a0
    li      $v0,    1           # load print integer flag into $v0s
    syscall                     # print the integer result

    la      $a0,    endl        # move enl into $a0
    li      $v0,    4           # load print string flag into $v0
    syscall                     # print the string ans

    li      $v0,    10          #load terminate flag into $v0
    syscall                     #terminate s

