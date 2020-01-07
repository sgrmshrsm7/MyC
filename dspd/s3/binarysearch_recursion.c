//Search for a given item in array using binary search algorithm using recursion.

#include <stdio.h>

int binarysearch(int a[], int hi, int lo, int num)
{
        int ret_val = -1, mid;
        if(hi >= lo)
        {
                mid = (hi + lo) / 2;
                if(a[mid] == num)
                        ret_val = mid;
                else if(a[mid] > num)
                        ret_val = binarysearch(a, mid - 1, lo, num);
                else
                        ret_val = binarysearch(a, hi, mid + 1, num);
        }
        return ret_val;
}

int main()
{
        int n, num, flag;
        printf("Enter size of the array : ");
        scanf("%d", &n);
        int a[n], i, hi, lo;
        printf("Enter elements in the array :");
        for(i = 0 ; i < n ; i++)
        {
                scanf("%d", &a[i]);
        }
        printf("\nEnter number to be searched : ");
        scanf("%d", &num);
        hi = n - 1;
        lo = 0;
        flag = binarysearch(a, hi, lo, num);
        if(flag != -1)
                printf("\nNumber found at index : %d", flag);
        else printf("\nNumber not found");
        return 0;
}
