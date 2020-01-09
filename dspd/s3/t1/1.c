//Solution of question number 1

#include <stdio.h>

int main()
{
        int n, i, sign = -1;
        float x, term, sum;
        printf("Enter value of x : ");
        scanf("%f", &x);
        printf("Enter value of n : ");
        scanf("%d", &n);
        term = x;
        sum = term;
        for(i = 1 ; i < n ; i++)
        {
                term = term * sign * x * x * (2 * i - 1) / (2 * i);
                sign *= -1;
                sum += (term / (2 * i + 1));
        }
        printf("\nSum of the series is : %f", sum);
        return 0;
}
