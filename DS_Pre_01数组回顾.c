#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    int *p = (int *)malloc(sizeof(int) * 10);
    p[1] = 12;
    printf("%d\n", p[1]);
    printf("%d\n", *(p + 1));
    free(p);
    return 0;
}
