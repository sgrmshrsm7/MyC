//Sorting an array using insertion sort

#include <stdio.h>

int main()
{
        int a[5], i, j, temp, n;
        n = 5;
        printf("Enter n = 5 numbers for storing in array :\n");
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
        for (i = 1 ; i < n ; i++)
        {
                temp = a[i];
                j = i - 1;
                while (j > (-1) && temp < a[j])
                {
                        a[j + 1] = a[j];
                        j--;
                }
                a[j + 1] = temp;
        }

        printf("\nSorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ",a[i]);
        }
        return 0;
}
