#include <stdio.h>
int main(void) {
    char *test;
    *test = 'a';
    *(test + 1) = 'b';
}