#include <stdio.h>

int main()
{
        int n, num, flag = 0;
        printf("Enter size of the array : ");
        scanf("%d", &n);
        int a[n], i;
        printf("Enter elements in the array :");
        for(i = 0 ; i < n ; i++)
        {
                scanf("%d", &a[i]);
        }
        printf("\nEnter number to be searched : ");
        scanf("%d", &num);
        for(i = 0 ; i < n && flag == 0 ; i++)
        {
                if(a[i] == num)
                        flag = 1;
        }
        if(flag == 1)
                printf("\nNumber found at index : %d", i-1);
        else printf("\nNumber not found");
        return 0;
}
