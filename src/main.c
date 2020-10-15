#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("is %d\n", a+b);
    printf("exit 0!\n");

    char *data = malloc(100);
    return 0;
}
