//Calculating factorial using tail recursion

#include <stdio.h>

int fact_t(int n, int acc)
{
        int ret_val;
        if((n == 0) || (n == 1))
        {
                ret_val = acc;
        }
        else
        {
                ret_val = fact_t(n-1, acc * n);
        }
        return ret_val;
}

int main()
{
        int a;
        printf("Enter number : ");
        scanf("%d", &a);
        printf("Factorial is : %d", fact_t(a, 1));
        return 0;
}
