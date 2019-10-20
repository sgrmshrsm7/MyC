//Find length of largest plateau in an array(largest period for which array is constant).

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], i, j, pl, plmax;
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        pl = 1;
        plmax = 1;
        for(i = 1 ; i < n ; i++)
        {
                if(a[i] == a[i - 1])
                        pl++;
                else
                {
                        if(pl > plmax)
                                plmax = pl;
                        pl = 1;
                }
        }
        if(pl > plmax)
                plmax = pl;
        printf("\nLength of largest plateau is : %d", plmax);
        return 0;
}
