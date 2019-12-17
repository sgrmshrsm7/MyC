//Count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

#include <stdio.h>

int countpath(int m, int n)
{
        if(m == 0 && n == 0)
                return 0;
        if(m == 1 || n == 1)
                return 1;
        else
                return countpath(m - 1, n) + countpath(m, n - 1);
}

int main()
{
        int M, N;
        printf("Enter value of M : ");
        scanf("%d", &M);
        printf("Enter value of N : ");
        scanf("%d", &N);
        printf("Number of paths = %d", countpath(M, N));
        return 0;
}
