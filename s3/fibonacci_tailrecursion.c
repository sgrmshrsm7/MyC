//Calculating nth fibonacci term using tail recursion

#include <stdio.h>

int fib_t(int n, int sec_term, int first_term)
{
        int ret_val;
        if (n == 1)
                ret_val = first_term;
        else
                ret_val = fib_t(n - 1, sec_term + first_term, sec_term);
        return ret_val;
}

int main()
{
        int n;
        printf("Enter the number(n) : ");
        scanf("%d",&n);
        printf("nth fibonacci term is : %d", fib_t(n,1,1));
}
