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
        int a[10], i;
        printf("Enter 10 numbers for the array :\n");
        for(i = 0;i < 10;i++)
                scanf("%d", &a[i]);
        quicksort(a, 0, 9);
        printf("Sorted array is : ");
        for(i = 0;i < 10;i++)
                printf("%d ", a[i]);
        return 0;
}
