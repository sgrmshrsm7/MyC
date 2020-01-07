//Calculating nth term of fibonacci series using recursion

#include <stdio.h>

int fib(int n)
{
        int ans;
        if (n == 1 || n == 2)
        {
                ans = 1;
        }
        else
        {
                ans = fib(n - 1) + fib(n - 2);
        }
        return ans;
}

int main()
{
        int n;
        printf("Enter number(n) : ");
        scanf("%d",&n);
        printf("nth fibonacci term is : %d",fib(n));
        return 0;
}
