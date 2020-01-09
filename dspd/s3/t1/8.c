//Solution of question number 8

#include <stdio.h>

int main()
{
        int x, n, i;
        float sum = 0, term;
        printf("Enter the value of x : ");
        scanf("%d", &x);
        printf("Enter the value of n : ");
        scanf("%d", &n);
        for(i = 0 ; i <= n ; i++)
        {
                term = (x - i) / (2.0 * i + 1);
                sum += term;
        }
        printf("Sum of the series = %f", sum);
        return 0;
}
