#include <iostream>
#include <algorithm>

using namespace std;

void disp(int *ptr, int count)
{
    int i = 0;
    //sort(ptr, ptr + count);
    sort(ptr, ptr + count, greater<int>()); // reverse

    unique(ptr, ptr + count);

    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }
    printf("\n\n");
}

double getAverage(int x[], int count)
{
    int i = 0;
    double j;
    for (i = 0; i < count; i++)
    {
        j += x[i];
    }
    return (j / count);
}

int main()
{
    /* an int array with 5 elements */
    int balance[] = {1000, 2, 3, 17, 50};
    double avg;
    int x = sizeof(balance) / sizeof(balance[0]);
    printf("count =%d \n", x);
    /* pass pointer to the array as an argument */
    disp(balance, x);

    return 0;
}