#include <stdio.h>

void func(void){
    printf("CSE 220\n");
}

int main()
{
    printf("Hello World\n");
    
    int fun=10;
    func();
    printf("The value of fun is %d\n", fun);

    return 0;
}
