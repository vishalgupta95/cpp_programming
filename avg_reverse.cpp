#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void disp(int *top, int count)
{
    int i = 0;
    int *ptr =top;
    sort(ptr, ptr + count, greater<int>()); // reverse

    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }



    printf("\n\n");
}

int main()
{
    /* an int array with 5 elements */
    int balance[] = {1000, 2, 3, 17, 50, 3, 19, 17, 14, 34};
    int x = sizeof(balance) / sizeof(balance[0]);
    printf("val =%d \n", x);
    disp(balance, x);

    return 0;
}
