//Find length of largest non-increasing sequence in an array.

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], i, j, ni, nimax;
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        ni = 1;
        nimax = 1;
        for(i = 1 ; i < n ; i++)
        {
                if(a[i] <= a[i - 1])
                        ni++;
                else
                {
                        if(ni > nimax)
                                nimax = ni;
                        ni = 1;
                }
        }
        if(ni > nimax)
                nimax = ni;
        printf("\nLength of non-increasing sequence is : %d", nimax);
        return 0;
}
