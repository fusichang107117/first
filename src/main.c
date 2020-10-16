#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
        return -1;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("is %d\n", a+b);
    printf("exit 0!\n");

    char *data = malloc(100);
    if (data) {
        char *a = malloc(100);
    }
    free(data);

    return 0;
}
