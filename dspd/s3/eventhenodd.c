//Given an unsorted array of integers. Transform array such that all even elements come first and then odd elements. Order among even elements should be preserved and same for odd elements.

#include <stdio.h>

int main()
{
        int n, i, j, s, temp;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n];
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        s = 1;
        for(i = 0 ; i < n && s == 1 ; i++)
        {
                s = 0;
                for(j = 0 ; j < n - i - 1 ; j++)
                        if(a[j] % 2 != 0 && a[j + 1] % 2 == 0)
                        {
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                                s = 1;
                        }
        }
        printf("\nResulting array is : ");
        for(i = 0 ; i < n ; i++)
                printf("%d", a[i]);
        return 0;
}
