#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// FILL IN THE BODY OF THIS FUNCTION.
// Feel free to create any other functions you like; just include them in this file.

/**
 * @brief Determine if the input is either 2 or S.
 *
 * @param input
 *      a character input.
 * @return 0 indicate it is an invalid input while 1 indicate it is a valid input.
 */
int verifyInput(char input)
{
    return (input == '2' || input == 'S');
}

/**
 * @brief Convert two's complement binary to signed.
 *
 * @param repr
 *      an unsigned, 32-bit value that represents an integer in the provided source representation.
 * @return int
 */
int twoToSigned(unsigned int repr)
{
    if ((repr & (1 << 31)))
    {
        repr = ~(repr - 1) | (repr & (1 << 31));
    }
    return repr;
}

/**
 * @brief
 *
 * @param repr
 *      an unsigned, 32-bit value that represents an integer in the provided source representation.
 * @return int
 */
int signedToTwo(unsigned int repr)
{
    if ((repr & (1 << 31)))
    {
        repr = ((~repr) + 1) | (repr & (1 << 31));
    }
    return repr;
}

/**
 * @brief takes an unsigned integer (repr) that provides the 32-bit representation of an integer
 *        and converts it from one integer representation to another.
 *        The function prints the  number in the target representation as an eight-digit hexadecimal value.
 *        Include a single newline at the end of the output. Include leading zeros in the output to pad out the eight digits.
 *        Any digits which are given as letters must be printed in lowercase.s
 *
 * @param source_repr
 *      the character '2' or 'S’, which indicates the integer representation the function is converting from.
 *      '2' indicates that the input is a 32-bit two's complement representation.
 *      'S' indicates that the input is a 32-bit sign/magnitude representation.
 * @param target_repr
 *      the character '2' or 'S', which indicates the integer representation the function is converting into.
 *      '2' and 'S' have similar interpretations for the source_repr argument,
 *      except that this character indicates the target representation.
 * @param repr
 *      an unsigned, 32-bit value that represents an integer in the provided source representation.s
 */
void repr_convert(char source_repr, char target_repr, unsigned int repr)
{
    if (!(verifyInput(source_repr) && verifyInput(target_repr)))
    {
        printf("error\n");
        return;
    }

    if (source_repr == target_repr)
    {
        printf("%08x\n", repr);
        return;
    }

    int result;
    switch (source_repr)
    {
    case '2':
        if (repr == 0x80000000)
        {
            printf("Undefined\n");
            return;
        }
        result = twoToSigned(repr);
        printf("%08x\n", result);
        break;
    default:
        if (repr == 0x80000000)
        {
            printf("%08x\n", 0x00000000);
            return;
        }
        result = twoToSigned(repr);
        printf("%08x\n", result);
        break;
    }
}

// DO NOT CHANGE ANY CODE BELOW THIS LINE
int main(int argc, char *argv[])
{
    (void)argc; // Suppress compiler warning
    (void)argv;

    repr_convert(argv[1][0], argv[2][0], (int)strtol(argv[3], NULL, 16));
    return 0;
}
