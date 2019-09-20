//Sorting an array using selection sort

#include <stdio.h>

int main()
{
        int a[5], i, j, temp, temp_pos, n;
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
        for (i = 0 ; i < n - 1 ; i++)
        {
                temp = a[i];
                temp_pos = i;
                for (j = i + 1 ; j < n ; j++)
                {
                        if (a[j] < temp)
                        {
                                temp = a[j];
                                temp_pos = j;
                        }
                }
                if (temp_pos != i)
                {
                        a[temp_pos] = a[i];
                        a[i] = temp;
                }
        }

        printf("\nSorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ",a[i]);
        }
        return 0;
}
