//Sorting an array using merge sort

#include <stdio.h>

void merge_self(int a[], int l, int m, int n, int c[])
{
        int i, j, k;
        i = l;
        j = m + 1;
        k = l;
        while(i <= m && j <= n)
        {
                if(a[i] < a[j])
                {
                        c[k++] = a[i++];
                }
                else
                {
                        c[k++] = a[j++];
                }
        }
        if(i <= m)
        {
                while(i <= m)
                        c[k++] = a[i++];
        }
        else
        {
                while(j <= n)
                        c[k++] = a[j++];
        }
        for(i = l;i <= n;i++)
                a[i] = c[i];
}

void mergesort(int a[], int c[], int lo, int hi)
{
        int mid;
        if(lo < hi)
        {
                mid = (lo + hi)/2;
                mergesort(a, c, lo, mid);
                mergesort(a, c, mid + 1, hi);
                merge_self(a, lo, mid, hi, c);
        }
}

int main()
{
        int a[10], c[10], i;
        printf("Enter 10 numbers for the array :\n");
        for(i = 0;i < 10;i++)
                scanf("%d", &a[i]);
        mergesort(a, c, 0, 9);
        printf("Sorted array is : ");
        for(i = 0;i < 10;i++)
                printf("%d ", a[i]);
        return 0;
}
