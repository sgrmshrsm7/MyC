// Remove duplicates in unsorted array

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n], i, j, k, flag;
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        j = 1;
        for(i = 1 ; i < n ; i++)
        {
                flag = 0;
                k = i - 1;
                while(flag == 0 && k >= 0)
                {
                        if(a[k] == a[i])
                                flag = 1;
                        k--;
                }
                if(flag == 0)
                {
                        a[j] = a[i];
                        j++;
                }
        }
        printf("\nNon - duplicated array(of size %d) is : ", j);
        for(i = 0 ; i < j ; i++)
                printf("%d ", a[i]);
        return 0;
}
