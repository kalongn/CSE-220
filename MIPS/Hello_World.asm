    # Program File: Hello_World.asm
    # Author: <REDACTED>
    # Purpose: First program, Hello World
.text                               # Define the program instructions
main:                               # Label to define the main program
    li      $v0,    4               # Load 4 into $v0
    la      $a0,    greeting        # Load the address of the greeting into $a0.
    syscall                         # Print greeting, the print is indicated by $v0 having a value of 4, and the string to print is stored in the address of $a0.

    li      $v0,    10              # Load a 10 (halt) into $v0
    syscall                         # The program ends.
.data                               # Define the program data
greeting:   .asciiz "Hello World"   # The String to print
