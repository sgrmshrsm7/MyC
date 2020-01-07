//A country has denominations of numbers in array Denom[] (user-input). Write a recursive function that returns -1 if it is not possible to pay a value k using those coins, Otherwise returns minimum number of coins to make payment.

#include <stdio.h>

int calculatechange(int k, int Denom[], int l)
{
        int ans = -1, flag = 1, i;
        if (k==0)
        {
                ans = 0;
                flag = 0;
        }
        for(i = 0; i < l && flag; i++)
        {
                if (k >= Denom[i])
                {
                        int ans1 = calculatechange(k - Denom[i], Denom, l);
                        if (ans1 != -1)
                        {
                                ans = ans1 + 1;
                                flag = 0;
                        }
                }
        }

        return ans;
}

int main()
{
        int k, Denom[1000], n, i;
        printf("Enter number of denominations : ");
        scanf("%d", &n);
        printf("Enter the %d denominations(in descending order) :\n", n);
        for(i = 0 ; i < n ; i++)
        {
                scanf("%d", &Denom[i]);
        }
        printf("\nYour denomination array is : [");
        for(i = 0 ; i < n ; i++)
        {
                printf("%d, ", Denom[i]);
        }
        printf("\b\b]");
        printf("\nEnter value of k : " );
        scanf("%d",&k);
        printf("Minimum number of coins required is : %d", calculatechange(k, Denom, n));
        return 0;
}
