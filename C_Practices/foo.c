#include <stdio.h>
int i = 1;
int counter()
{
    i = i + 1;
    return i;
}
int foo(int i, int j)
{
    return i * 2 + 3 * j;
}
int main(void)
{
    printf("%d", foo(counter(), counter()));
    return 0;
}