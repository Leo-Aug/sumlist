#include <stdio.h>

int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int sum_list(int n);

int main(void)
{
    printf("%d", sum_list(10));
    return 0;
}

int sum_list(int n)
{
    if(n == 1)
    {
        return list[0];
    }
    else
    {
        return sum_list(n - 1) + list[n - 1];
    }
}