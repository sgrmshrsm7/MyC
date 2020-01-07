//Sorting an array using modified bubble sort

#include <stdio.h>

int main()
{
        int i, j, temp, n, s;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n];
        printf("Enter n = %d numbers for storing in array :\n", n);
        for (i = 0 ; i < n ; i++)
        {
                scanf("%d",&a[i]);
        }
        printf("\nUnsorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ",a[i]);
        }

        //Sort starts here
        s = 1;
        for (i = 0 ; i < n - 1 && s == 1; i++)
        {
                s = 0;
                for (j = 0 ; j < n - 1 - i ; j++)
                {
                        if (a[j] > a[j + 1])
                        {
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                                s = 1;
                        }
                }
        }

        printf("\nSorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ",a[i]);
        }
        return 0;
}
