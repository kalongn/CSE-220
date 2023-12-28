.data   
ans:    .asciiz "Answer :"
endl:   .asciiz "\n"
x:      .word   6               #.word is 4 bytes aka integer
A:      .word   3
B:      .word   4
C:      .word   5


.text                           #Compute Ax^2 + Bx + c
main:   
    lw      $t0,    x           # load x into $t0
    lw      $t1,    A           # load A into $t1
    lw      $t2,    B           # load B into $t2
    lw      $t3,    C           # load C into $t3

    #Calculaiton
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

