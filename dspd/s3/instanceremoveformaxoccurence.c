//Given sorted array, remove all instances of number which appears maximum number of times. If multiple number with same number of instances then consider number whichever comes first.

#include <stdio.h>

int main()
{
        int n;
        printf("Enter size of the array : ");
        scanf("%d", &n);
        int a[n], i, j, count, num, count_max;
        printf("Enter %d numbers for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        num = a[0];
        count = 1;
        count_max = 1;
        for(i = 1 ; i < n ; i++)
        {
                if(a[i] == a[i-1])
                        count++;
                else
                {
                        if(count > count_max)
                        {
                                num = a[i - 1];
                                count_max = count;
                        }
                        count = 1;
                }
        }
        if(count > count_max)
        {
                num = a[i - 1];
                count_max = count;
        }
        for(i = 0 ; a[i] != num ; i++);
        n = n - count_max;
        while(i < n)
        {
                a[i] = a[i + count_max];
                i++;
        }
        printf("\nNew array is : ");
        for(i = 0 ; i < n ; i++)
                printf("%d ", a[i]);
        return 0;
}
