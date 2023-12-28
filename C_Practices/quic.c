#include <stdio.h>
int main()
{
    int i = 0x1234abcd, n;
    unsigned char *byte = (unsigned char *)&i;

    for (n = 0; n < 4; n++)
    {
        printf("%x", *(byte + n));
    }

    return 0;
}