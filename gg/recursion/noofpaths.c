//Count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

#include <stdio.h>

int main()
{
        int M, N;
        printf("Enter value of M : ");
        scanf("%d", &M);
        printf("Enter value of N : ");
        scanf("%d", &N);
        int a[M][N], i , j;
        for(i = 0 ; i < M ; ++i)
                a[i][0] = 1;
        for(i = 0 ; i < N ; ++i)
                a[0][i] = 1;
        for(i = 1 ; i < M ; ++i)
                for(j = 1 ; j < N ; ++j)
                        a[i][j] = a[i-1][j] + a[i][j-1];
        printf("Number of paths = %d", a[M - 1][N - 1]);
        return 0;
}
