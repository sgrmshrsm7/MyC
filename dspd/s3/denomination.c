//A country has denominations of 3,5 & 10. Write a recursive function that returns -1 if it is not possible to pay a value k using those coins, Otherwise returns minimum number of coins to make payment.
//Write another function to print change.

#include <stdio.h>

int n3 = 0, n5 = 0, n10 = 0;

int calculatechange(int k)
{
        int ans = -1, flag = 1;
        if (k==0)
        {
                ans = 0;
                flag = 0;
        }
        if (k >= 10 && flag)
        {
                int ans1 = calculatechange(k - 10);
                if (ans1 != -1)
                {
                        ans = ans1 + 1;
                        n10++;
                        flag = 0;
                }
        }
        if (k >= 5 && flag)
        {
                int ans1 = calculatechange(k - 5);
                if (ans1 != -1)
                {
                        ans = ans1 + 1;
                        n5++;
                        flag = 0;
                }
        }
        if (k >= 3 && flag)
        {
                int ans1 = calculatechange(k - 3);
                if (ans1 != -1)
                {
                        ans = ans1 + 1;
                        n3++;
                        flag = 0;
                }
        }
        return ans;
}

void printchange()
{
        printf("\nNo of 3 coins are : %d", n3);
        printf("\nNo of 5 coins are : %d", n5);
        printf("\nNo of 10 coins are : %d", n10);
}

int main()
{
        int k;
        printf("Enter value of k : " );
        scanf("%d",&k);
        printf("Minimum number of coins required is : %d", calculatechange(k));
        printchange();
        return 0;
}
