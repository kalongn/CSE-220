    # Program File: Print_Char.asm
    # Author: <REDACTED>
    # Purpose: Print a character
.data                           # define data
character:  .byte   'A'         # a character of a value 'a'

.text   
main:       
    li      $v0,    11          # Load 11 into v0
    lb      $a0,    character   # Load character into a0
    syscall                     # Print character

    li      $v0,    10          # Load a 10 (halt) into $v0
    syscall                     # The program ends.

