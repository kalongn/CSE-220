.data   
pinA:               .space  400                                     # We will not change this
pinB:               .space  400                                     # We will not change this

num:                .word   n                                       # We can change this n x 4 <= 400 This is the constraint

A:                  .asciiz "A["
B:                  .asciiz "B["
C:                  .asciiz "]="
spacechar:          .asciiz " "
bar:                .asciiz "|"
newline:            .asciiz "\n"
notAValidArraySize: .asciiz "n is not a valid dimension"

.text   
main:               
    la      $s0,                pinA                                # load the memory address of A array
    la      $s1,                pinB                                # load the memory address of B array
    lw      $t0,                num                                 # load the size of the given number
    blt     $t0,                1,                  errorDimension  # no a valid array
    bgt     $t0,                100,                errorDimension  # also not a valid array
    li      $t1,                0                                   # load the looping variable for first variable

whileloop:          
    beq     $t1,                $t0,                printArray      # if we reach limit, exit while loop and go to printArray branch
    addi    $t1,                $t1,                1               # increment (from 0-indexed to 1-indexed)

    la      $a0,                A                                   # load A into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall                                                         # print the promt

    move    $a0,                $t1                                 # load current (1-indexed) item into $a0
    li      $v0,                1                                   # load integer printflag into $v0
    syscall 

    la      $a0,                C                                   # load C into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall 

    li      $v0,                5                                   # load integer scan flag into $v0
    syscall                                                         # obtain the scan input

    move    $t3,                $v0                                 # load A[i] into $t3

    la      $a0,                B                                   # load B into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall                                                         # print the promt

    move    $a0,                $t1                                 # load current (1-indexed) item into $a0
    li      $v0,                1                                   # load integer printflag into $v0
    syscall 

    la      $a0,                C                                   # load C into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall 

    li      $v0,                5                                   # load integer scan flag into $v0
    syscall                                                         # obtain the scan input

    move    $t4,                $v0                                 # load B[i] into t4

    sw      $t3,                0($s0)                              # save A[i] into A[i]
    sw      $t4,                0($s1)                              # save B[i] into B[i]

    addi    $s0,                $s0,                4               # increment address of A array by 4 (an integer size)
    addi    $s1,                $s1,                4               # increment address of B arrat by 4 (an integer size)

    j       whileloop

printArray:         
    la      $s2,                pinA                                # load address of beginning of A array to $s2
    la      $s3,                pinB                                # load address of beginning of B array to $s3
secondWhileLoop:    
    beq     $s2,                $s0,                exit            # while ($s2 != $s0) (means we are not up to the memory address which we read up to)

    lw      $t0,                0($s2)                              # load integer at s2 into t0
    lw      $t1,                0($s3)                              # load integer at s3 into t1
    sw      $t1,                0($s2)                              # save integer t1 into s2
    sw      $t0,                0($s3)                              # save integer t0 into s3

    lw      $a0,                0($s2)                              # load A[i] into $a0
    li      $v0,                1                                   # load integer scan flag into $v0
    syscall                                                         # print integer

    la      $a0,                spacechar                           # load " " into $a0
    li      $v0,                4                                   # load String scan flag into $v0
    syscall                                                         # pint String

    lw      $a0,                0($s3)                              # load B[i] into $a0
    li      $v0,                1                                   # load integer scan flag into $v0
    syscall                                                         # print integer

    la      $a0,                bar                                 # load "|" into $a0
    li      $v0,                4                                   # load integer scan flag into $v0
    syscall                                                         # print integer

    addi    $s2,                $s2,                4               # increment memory address of $s2 by 4 (integer is 4 bytes)
    addi    $s3,                $s3,                4               # increment memory address of $s3 by 4 (integer is 4 bytes)

    j       secondWhileLoop                                         # continue loop

errorDimension:     
    la      $a0,                notAValidArraySize                  # load a notAValidArraySize into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall                                                         # pint the newline
    j       exit                                                    # exit program

printNewLine:       
    la      $a0,                newline                             # load a newline into $a0
    li      $v0,                4                                   # load print string flag into $v0
    syscall                                                         # pint the newline
    jr      $ra                                                     # go back to callstack

exit:               
    jal     printNewLine
    li      $v0,                10                                  # load terminate flag into $v0
    syscall                                                         # exit function
