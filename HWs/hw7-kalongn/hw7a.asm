    ############################################
    # Triangle(0) or Square(1) or Pyramid (2)?1
    # Required size? 3
    #       
    # ***
    # ***
    # ***
    # -- program is finished running --
    ############################################

.data   
promtShape: .asciiz "Triangle (0) or Square (1) or Pyramid (2) ? "
wrongShape: .asciiz "Provided input is not a valid shape input."
wrongSize:  .asciiz "Provided input is not a valid row."
promtSize:  .asciiz "Required Size? "
newline:    .asciiz "\n"
asterisk:   .asciiz "*"
space:      .asciiz " "


.text   
main:       

promtShapeSegment:
    la      $a0,                            promtShape                                  # load promtShape into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    li      $v0,                            5                                           # load integer scan flag into $v0
    syscall                                                                             # obtain the scan input
    move    $t0,                            $v0                                         # store the input into $t0

    blt     $t0,                            0,          notAShapeOption                 # input is less then 0 which is not an shape option
    bgt     $t0,                            2,          notAShapeOption                 # input is greater then 2 which is not an shape option

promtSizeSegment:
    la      $a0,                            newline                                     # load a newline into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # pint the newline

    la      $a0,                            promtSize                                   # load promtSize into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    li      $v0,                            5                                           # load integer scan flag into $v0
    syscall                                                                             # obtain the scan input
    move    $a0,                            $v0                                         # store the input into $t1

    blt     $a0,                            0,          notAValidRow                    # exception handling

    beq     $t0,                            0,          printTriangle                   # jump to triangle if shape input is 0
    beq     $t0,                            1,          printSquare                     # jump to Square if shape input is 1
    beq     $t0,                            2,          printPyramid                    # jump to Pyramid if shape input is 2

printSquare:
    move    $t1,                            $a0                                         # move input argument into $t1
    li      $t2,                            0                                           # outer loop variable
printSquareLoop:
    beq     $t2,                            $t1,        exit                            # end of while loop while($t2 < $t1)
    jal     printNewLine                                                                # print new line (at each of iteration of the outer while loop)
    addi    $t2,                            $t2,        1                               # increment the outerloop (%t2++)
    add     $a0,                            $0,         $t1                             # print_star_line loop variable
    jal     print_star_line                                                             # print amount of stars
    j       printSquareLoop                                                             # continue the loop

printTriangle:
    move    $t1,                            $a0                                         # move input argument into $t1
    li      $t2,                            0                                           # outer loop variable
printTriangleLoop:
    beq     $t2,                            $t1,        exit                            # end of whike loop while($t2 < $t1)
    jal     printNewLine                                                                # print new line (at each of iteration of the outer while loop)
    addi    $t2,                            $t2,        1                               # increment the outerloop (%t2++)
    add     $a0,                            $0,         $t2                             # print_star_line loop variable
    jal     print_star_line                                                             # print amount of stars
    j       printTriangleLoop                                                           # continue the loop

printPyramid:
    move    $t1,                            $a0                                         # move input argument into $t1
    li      $t2,                            0                                           # outer loop variable
printPyramidLoop:
    beq     $t2,                            $t1,        exit                            # end of while loop while($t2 < $t1)
    jal     printNewLine                                                                # print a new line
    addi    $t2,                            $t2,        1                               # increment loop variable
    sub     $t3,                            $0,         $t2                             # set $t3 = 0 - $t2 (which is our first loop variable)
    add     $t3,                            $t3,        $t1                             # $t3 = %t1 - $t2 (this and the previous line)
    li      $t4,                            0                                           # load 0 into another inner loop variable

print_star_line_Pyramid_First:
    beq     $t3,                            0,          print_star_line_Pyramid_Second  # end of the first while loop while($t3 > 0)
    la      $a0,                            space                                       # load space into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the space
    addi    $t3,                            $t3,        -1                              # decrement the loopping variables
    j       print_star_line_Pyramid_First                                               # continue the first inner loop

print_star_line_Pyramid_Second:
    beq     $t4,                            $t2,        printPyramidLoop                # end of while loop while($t4 < $t2)
    la      $a0,                            asterisk                                    # load asterisk into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the asterisk
    la      $a0,                            space                                       # load space into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the space
    addi    $t4,                            $t4,        1                               # increment $t4 which is this second loop lopping variable
    j       print_star_line_Pyramid_Second                                              # continue the loop

notAShapeOption:
    la      $a0,                            wrongShape                                  # load wrong string input to $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the the message
    j       exit                                                                        # jump to exit

notAValidRow:
    la      $a0,                            wrongSize                                   # load wrong string input to $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the message
    j       exit                                                                        # jump to exit

print_star_line:
    move    $t3,                            $a0
print_star_line_loop:
    beq     $t3,                            0,          jumpback
    la      $a0,                            asterisk                                    # load asterisk into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the asterisk
    addi    $t3,                            $t3,        -1                              # decrement the innerloop
    j       print_star_line_loop                                                        # continue the inner loop

printNewLine:
    la      $a0,                            newline                                     # load a newline into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # pint the newline
    j       jumpback                                                                    # go back to callstack

jumpback:                                                                               # a label simply jump to the return address (for branches)
    jr      $ra                                                                         # jump to return address

exit:       
    jal     printNewLine
    li      $v0,                            10                                          # load terminate flag into $v0
    syscall                                                                             # exit function
