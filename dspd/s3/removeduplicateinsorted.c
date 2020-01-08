//Remove duplicates from a sorted array

#include <stdio.h>

int main()
{
        int n;
        printf("Enter number of elemets in the array : ");
        scanf("%d", &n);
        int a[n], i, j;
        printf("Enter %d elements of sorted array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        j = 1;
        for(i = 1 ; i < n ; i++)
                if(a[i] != a[i - 1])
                        {
                                a[j] = a[i];
                                j++;
                        }
        printf("\nNon - duplicated array(of size %d) is : ", j);
        for(i = 0 ; i < j ; i++)
                printf("%d ", a[i]);
        return 0;
}
