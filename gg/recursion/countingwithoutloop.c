//Print numbers from 1 to N without the help of loops.

#include <stdio.h>

void count(int n, int N)
{
        if(n > 0)
        {
                printf("%d ", N-n+1);
                count(n - 1, N);
        }
}

int main()
{
        int N;
        printf("Enter the value value of N : ");
        scanf("%d", &N);
        count(N, N);
        return 0;
}
