#include <stdio.h>
#include <stdlib.h>

int count;
float costs[100];

void inc(int x);

int main(void)
{
    printf("Hello World!\n");
    printf("count is: %d\n", count);
    inc(5);
    printf("count is: %d\n", count);
}

void inc(int x)
{
    int y;
    count = x + 1;
}