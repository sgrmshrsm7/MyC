//Find length of largest non-decreasing sequence in an array.

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], i, j, nd, ndmax;
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        nd = 1;
        ndmax = 1;
        for(i = 1 ; i < n ; i++)
        {
                if(a[i] >= a[i - 1])
                        nd++;
                else
                {
                        if(nd > ndmax)
                                ndmax = nd;
                        nd = 1;
                }
        }
        if(nd > ndmax)
                ndmax = nd;
        printf("\nLength of non-decreasing sequence is : %d", ndmax);
        return 0;
}
