//Print numbers from 1 to N without the help of loops.

#include <stdio.h>

void count(int n)
{
        if(n > 0)
        {
                count(n - 1);
                printf("%d ", n);
        }
}

int main()
{
        int N;
        printf("Enter the value value of N : ");
        scanf("%d", &N);
        count(N);
        return 0;
}
