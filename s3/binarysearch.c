//Search for a given item in array using binary search algorithm.

#include <stdio.h>

int main()
{
        int n, num, flag = 0;
        printf("Enter size of the array : ");
        scanf("%d", &n);
        int a[n], i, hi, lo, mid;
        printf("Enter elements in the array :");
        for(i = 0 ; i < n ; i++)
        {
                scanf("%d", &a[i]);
        }
        printf("\nEnter number to be searched : ");
        scanf("%d", &num);
        hi = n - 1;
        lo = 0;
        while(flag != 1 && hi > lo)
        {
                mid = (hi + lo) / 2;
                if(a[mid] == num)
                        flag = 1;
                else if(a[mid] > num)
                        hi = mid - 1;
                else
                        lo = mid + 1;
        }
        if(flag == 1)
                printf("\nNumber found at index : %d", mid);
        else printf("\nNumber not found");
        return 0;
}
