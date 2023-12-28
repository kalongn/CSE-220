#include <stdio.h>

/**
 * @brief Convert the input with 3 parts to construct a IEEE 754 single precision float.
 *
 * @param sign_bit
 *      The sign bit zero-extended to 8-bit binary representation.
 * @param exponent
 *      The exponent field in 8-bit, excess-127 binary representation.
 * @param fraction
 *      The fraction field, or matissa, zero-extended to 32-bit representation.
 * @return IEEE 754 of the given input in float.
 */
float construct_float_sf(char sign_bit, char exponent, unsigned int fraction)
{
    /* DO NOT CHANGE THE DECLARATION OF "f" (This will be converted to float later) */
    unsigned int f = 0; // DO NOT CHANGE
    /*------------------------------------------------------------------------------*/

    /* Start Coding Here */
    f = ((unsigned char)sign_bit << 31) + ((unsigned char)exponent << 23) + (fraction & 0x7FFFFF);
    // printf("%x", f);

    /*-------------------*/

    /* DO NOT CHANGE THE RETURN VALUE (This returns the binary representation of "f" as float) */
    return *((float *)&f); // DO NOT CHANGE
    /* ----------------------------------------------------------------------------------------*/
}

int main(int argc, char *argv[])
{
    (void)argc; // to supress compiler warning
    (void)argv; // to supress compiler warning
    printf("f = %g\n", construct_float_sf(0x00, 0x00, 0x000000));

    return 0;
}
