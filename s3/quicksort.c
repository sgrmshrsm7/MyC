//Sorting an array using quick sort

#include <stdio.h>

int partition(int a[], int lo, int hi)
{
        int pivot = a[hi];
        int i = lo - 1, j, temp;
        for(j = lo;j < hi;j++)
        {
                if(a[j] <= pivot)
                {
                        i++;
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }
        }
        temp = a[i+1];
        a[i+1] = a[hi];
        a[hi] = temp;
        return i + 1;
}

void quicksort(int a[], int lo, int hi)
{
        if(lo < hi)
        {
                int pi = partition(a,lo,hi);
                quicksort(a, lo, pi - 1);
                quicksort(a, pi + 1, hi);
        }
}

int main()
{
        int n, i;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], c[n];
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
        quicksort(a, 0, n-1);
        printf("\nSorted array is : ");
        for(i = 0;i < n;i++)
                printf("%d ", a[i]);
        return 0;
}
