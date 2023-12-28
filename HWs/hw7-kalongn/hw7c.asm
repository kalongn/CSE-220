.data   
M:              .space  400                                                             # int M[][] The matrix
V:              .space  400                                                             # int V[]   The vector
C:              .space  400                                                             # int C[] : The output vector
m:              .word   10                                                              # m is an int whose value is at most 10
    # max value for rows and columns
col_m:          .word   5                                                               # columns for matrix M: This should not be more than 10
row_m:          .word   5                                                               # rows for matrix M: This should not be more than 10
    # (col_m * row_m) * 4 <= M
col_v:          .word   1                                                               # colums for vector V. For a vector, the column is always one
row_v:          .word   5                                                               # rows for vector V. This should not be more than 10
    # (col_v * row_v) * 4 <= V
    # You may add more variables here if you need to
newline:        .asciiz "\n"
ReadInputLeft:  .asciiz "Enter Element "
ReadInputRight: .asciiz "= "
LargerThenMem:  .asciiz "NOT WORKABLE BECAUSE OF THE MEMORY"
DimensionWrong: .asciiz "NOT WORKABLE BECAUSE OF THE DIMENSIONS"
bracketLeft:    .asciiz "[ "
space:          .asciiz " "
bracketRight:   .asciiz "]"


.text   

main:           
    #------- INSERT YOUR CODE HERE for main -------
    #       
    #  The best is to convert the C program line by line
    #    into its assembly equivalent.
    #       
    #       
    #       
    #       
    #------------ END CODE ---------------

    # la      $s0,                            M                                           # save matrix address to $s0
    # la      $s1,                            V                                           # save vector address to $s1
    # la      $s2,                            C                                           # save output vector address to $s2

    lw      $a0,                            row_m                                       # save the row (dimension of matrix n*n) into input argument for read_matrix $a0
    lw      $a1,                            col_m                                       # save the column (dimension of matrix n*n) into input argument for read_matrix $a0
    blt     $a0,                            1,              MVM_error                   # exception handling if dimension is less then 1
    blt     $a1,                            1,              MVM_error                   # exception handling if dimension is less then 1
    jal     read_matrix                                                                 # jump and link to read_matrix function
    move    $s0,                            $v0                                         # save the output of read_matrix into $s0

    jal     printNewLine                                                                # print a line to seperate between the Matrix and Vector input

    lw      $a0,                            row_v                                       # save row (diemension of vector) into input argument for read_vector $a0
    blt     $a0,                            1,              MVM_error                   # exception handling if dimension is less then 1
    jal     read_vector                                                                 # jump and link to read_vector function
    move    $s1,                            $v0                                         # save the output of read_vector into $s1

    lw      $a0,                            row_m                                       # save the row_m into argument for MVM $a0
    lw      $a1,                            col_m                                       # save the col_m into argument for MVM $a1
    lw      $a2,                            row_v                                       # save the row_v into argument for MVM $a2
    la      $a3,                            M                                           # save the M address into argument for MVM $a3
    la      $t4,                            V                                           # save the V address into argument for MVM $t4 (which will be saved to the stack)

    addiu   $sp,                            $sp,            -4                          # provide space to store the return address onto the stack
    sw      $t4,                            0($sp)                                      # save the current return address into the stack

    jal     MVM                                                                         # jump and link to inner iteration

    addiu   $sp,                            $sp,            4                           # deallocate space on the stack
    move    $s2,                            $v0                                         # obtain pointer C

    jal     printNewLine

    lw      $a0,                            row_m                                       # the dimension of C
    move    $a1,                            $s2                                         # the pointer of C store in $a1
    jal     print_vector                                                                # print vector C

    j       exit                                                                        # jump to exit label

MVM:                                                                                    # FUNCTION $a0: row of matrix, $a1: col of matrix, $a2: row of vector, $a3: pointer to matrix M, $t4 (saved on stack pointer): pointer to Vector
    lw      $t0,                            0($sp)                                      # load the input argument of $t4 ( on stack pointer) and store it into $t4

    bne     $a1,                            $a2,            MVM_error                   # if col of matrix and row of vector does not agree, cannot perform multiplication

    la      $t2,                            C                                           # load the output address into $t2 (where we will store our result from this multiplication)
    li      $t3,                            0                                           # outer loop variable
MVM_outer_loop: 
    beq     $t3,                            $a0,            MVM_return

    li      $t4,                            0                                           # sum variable store into $t4
    li      $t5,                            0                                           # inner loop variable

    addiu   $sp,                            $sp,            -4                          # provide space to store the return address onto the stack
    sw      $ra,                            0($sp)                                      # save the current return address into the stack
    jal     MVM_inner_loop                                                              # jump and link to inner iteration
    lw      $ra,                            0($sp)                                      # load the return address back once the MVM_inner_loop function exit
    addiu   $sp,                            $sp,            4                           # deallocate space on the stack

    sw      $t4,                            0($t2)                                      # save the sum we've got from inner loop into the C[j]

    addi    $t2,                            $t2,            4                           # increment memeory by 4
    addi    $t3,                            $t3,            1                           # increment loop index by 1
    j       MVM_outer_loop                                                              # continue iteration

MVM_inner_loop: 
    beq     $t5,                            $a2,            jumpback                    # loop done, return to MVM_outer loop

    mul     $t6,                            $a1,            $t3                         # row_index * col_amount and store into $t6
    add     $t6,                            $t6,            $t5                         # row_index * col_amount + col_index and store into $t6
    sll     $t6,                            $t6,            2                           # 4 * ( row_index * col_amount + col_index) and store into $t6
    add     $t6,                            $a3,            $t6                         # base_address + 4 * ( row_index * col_amount + col_index) and store into $t6
    lw      $t6,                            0($t6)                                      # load the content at M[i][j]

    sll     $t7,                            $t5,            2                           # 4 * row_index of vector
    add     $t7,                            $t7,            $t0                         # base address + 4 * row_index of vector
    lw      $t7,                            0($t7)                                      # load the content of V[j]

    mul     $t6,                            $t6,            $t7                         # M[i][j] * V[j]
    add     $t4,                            $t4,            $t6                         # sum = sum + M[i][j] * V[j]

    addi    $t5,                            $t5,            1                           # j++
    j       MVM_inner_loop                                                              # continue iteration

MVM_return:     
    la      $v0,                            C                                           # store the memory address of the matrix we read into $v0
    j       jumpback                                                                    # jumpback aka exiting the function or MVM

MVM_error:      
    la      $a0,                            DimensionWrong                              # load error message into $a0
    li      $v0,                            4                                           # load string print flag into $v0
    syscall                                                                             # print the error message
    j       exit                                                                        # exit the funciton as error occured


read_vector:                                                                            # FUNCTION $a0 = n amount of elements
    move    $t0,                            $a0                                         # load the input argument of $a0 and store it into $t0
    li      $t2,                            0                                           # store the normal value of indexing into $t2 (for printing purposes)
    la      $t1,                            V                                           # store the address of V vector (which is what this function writes to)
    sll     $t0,                            $t0,            2                           # multiply the n amount by 4
    bgt     $t0,                            400,            read_matrix_error           # if input size for vector is greater then 100 (aka memory space greater then 400, exit with error)
    add     $t0,                            $t0,            $t1                         # by adding the n amount by 4 and the actual memory address of the vector, we essentialy calculated the bound for the array to read up to
read_vector_loop:
    beq     $t1,                            $t0,            read_vector_return          # if we reach the bound. exit the function by going to the read_vector_return label with jump to return address
    addi    $t2,                            $t2,            1                           # increment the display looping index by 1

    la      $a0,                            ReadInputLeft                               # load ReadInputLeft into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    add     $a0,                            $0,             $t2                         # load current index $t2 into $a0
    li      $v0,                            1                                           # load integer-print flag into $v0
    syscall                                                                             # print the integer

    la      $a0,                            ReadInputRight                              # load ReadInputRight into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    li      $v0,                            5                                           # load integer scan flag into $v0
    syscall                                                                             # scan the input
    sw      $v0,                            0($t1)                                      # store current user input into V[i]

    addi    $t1,                            $t1,            4                           # increment the looping variable by 4 (memory address)
    j       read_vector_loop                                                            # continue the loop
read_vector_return:
    la      $v0,                            V                                           # store the memory address of the array we read into $v0
    j       jumpback                                                                    # jumpback aka exiting the function or read_vector

read_matrix:                                                                            # FUNCTION $a0 = n such that we can create a n*n matrix
    move    $t0,                            $a0                                         # load the input argument of $a0 and store it into $t0
    move    $t5,                            $a1                                         # load the input argument of $a1 and store it into $t5

    mul     $t7,                            $t0,            $t5                         # calcuate row * col
    sll     $t7,                            $t7,            2                           # calculate row * col * 4
    bgt     $t7,                            400,            read_matrix_error           # if ( row * col * r > 400) , exit with error

    li      $t6,                            1                                           # load the looping index (for display) and set it to 1
    la      $t1,                            M                                           # load the address of M matrix into $t1
    li      $t2,                            -1                                          # store the normal value of row indexing into $t2 (for printing purposes)
read_matrix_row_iteration:
    addi    $t2,                            $t2,            1                           # increment the row index by 1 (as exit from column_index)
    beq     $t2,                            $t0,            read_matrix_return          # exit function as iteration finished
    li      $t3,                            0                                           # store the normal value of column indexing into $t3 (for printing purposes)
read_matrix_column_iteration:
    beq     $t3,                            $t5,            read_matrix_row_iteration
    mul     $t4,                            $t2,            $t5                         # row_index * col_amount and store into $t4
    add     $t4,                            $t4,            $t3                         # row_index * col_amount + col_index and store into $t4
    sll     $t4,                            $t4,            2                           # 4 * ( row_index * col_amount + col_index) and store into $t4
    add     $t4,                            $t1,            $t4                         # base_address + 4 * ( row_index * col_amount + col_index) and store into $t4

    la      $a0,                            ReadInputLeft                               # load ReadInputLeft into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    add     $a0,                            $0,             $t6                         # load current element $t6 into $a0
    li      $v0,                            1                                           # load integer-print flag into $v0
    syscall                                                                             # print the integer

    la      $a0,                            ReadInputRight                              # load ReadInputRight into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # print the promt

    li      $v0,                            5                                           # load integer scan flag into $v0
    syscall                                                                             # scan the input
    sw      $v0,                            0($t4)                                      # store current user input into M[i][j]

    addi    $t3,                            $t3,            1                           # increment column_index by 1
    addi    $t6,                            $t6,            1                           # increment the display_index by 1
    j       read_matrix_column_iteration                                                # continue iteration
read_matrix_return:
    la      $v0,                            M                                           # store the memory address of the matrix we read into $v0
    j       jumpback                                                                    # jumpback aka exiting the function or read_matrix
read_matrix_error:
    la      $a0,                            LargerThenMem                               # load error message into $a0
    li      $v0,                            4                                           # load string print flag into $v0
    syscall                                                                             # print the error message
    j       exit                                                                        # exit the funciton as error occured


print_vector:                                                                           # FUNCTION $a0 = n amount of elements, $a1, the address of the vector
    move    $t0,                            $a0                                         # load the input argument of $a0 and store it into $t0
    move    $t1,                            $a1                                         # load the input argument of $a1 and store it into %t1
    sll     $t0,                            $t0,            2                           # multiply the n element by 4 such that we can use memory address to loop
    add     $t0,                            $t0,            $t1                         # by adding the n amount by 4 and the actual memory address of the vector, we essentialy calculated the bound for the array to read up to

    la      $a0,                            bracketLeft                                 # print open bracket
    li      $v0,                            4
    syscall 

    addiu   $sp,                            $sp,            -4                          # provide space to store the return address onto the stack
    sw      $ra,                            0($sp)                                      # save the current return address into the stack
    jal     print_vector_loop                                                           # jump and link to inner iteration
    lw      $ra,                            0($sp)                                      # load the return address back once the printNewLine function exit
    addiu   $sp,                            $sp,            4                           # deallocate space on the stack

    la      $a0,                            bracketRight                                # load the closing bracket into $a0
    li      $v0,                            4                                           # load the string print flag into $v0
    syscall                                                                             # print string

    j       jumpback                                                                    # exit function

print_vector_loop:
    beq     $t1,                            $t0,            jumpback                    # if we reach the bound. exit the function by going to the jumpback label with jump to return address

    lw      $a0,                            0($t1)                                      # load the current word at index $t0 into $a0
    li      $v0,                            1                                           # load integer print flag
    syscall                                                                             # print the integer

    la      $a0,                            space                                       # load the space string into $a0
    li      $v0,                            4                                           # load string print flag
    syscall                                                                             # print the string

    addi    $t1,                            $t1,            4                           # increment the memory by 4 (aka the next elements)

    j       print_vector_loop                                                           # continue the loop


jumpback:                                                                               # a label simply jump to the return address (for branches)
    jr      $ra                                                                         # jump to return address


printNewLine:   
    la      $a0,                            newline                                     # load a newline into $a0
    li      $v0,                            4                                           # load print string flag into $v0
    syscall                                                                             # pint the newline
    j       jumpback                                                                    # go back to callstack

exit:           
    jal     printNewLine
    li      $v0,                            10                                          # load terminate flag into $v0
    syscall                                                                             # exit function

    #------- If you decide to make other functions, place their code here -------
    #       
    #  You do not have to use helper methods, but you may if you would like to.
    #  If you do use them, be sure to do all the proper stack management.
    #       
    #------------ END CODE ---------------
