//Sorting an array using shell sort

#include <stdio.h>

int main()
{
        int i, j, temp, gap, n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n];
        printf("Enter n = %d numbers for storing in array :\n", n);
        for (i = 0 ; i < n ; i++)
        {
                scanf("%d", &a[i]);
        }
        printf("\nUnsorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ", a[i]);
        }

        //Sort starts here
        for (gap = n / 2; gap > 0; gap /= 2)
        {
                for (i = gap; i < n; i += 1)
                {
                        temp = a[i];
                        for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                        a[j] = a[j - gap];
                        a[j] = temp;
                }
        }

        printf("\nSorted array is : ");
        for (i = 0 ; i < n ; i++)
        {
                printf("%d ", a[i]);
        }
        return 0;
}
