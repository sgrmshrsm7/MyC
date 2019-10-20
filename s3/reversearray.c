//Reverse an integer array

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], i, temp;
        printf("Enter %d numbers for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        for(i = 0 ; i < n/2 ; i++)
        {
                temp = a[i];
                a[i] = a[n - 1 - i];
                a[n - 1 - i] = temp;
        }
        printf("\nReversed array is : ");
        for(i = 0 ; i < n ; i++)
                printf("%d ", a[i]);
        return 0;
}
