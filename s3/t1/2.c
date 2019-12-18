//Solution of question number 2

#include <stdio.h>

int main()
{
        float x, term, sum = 0;
        int i;
        printf("Enter the value of x : ");
        scanf("%f", &x);
        term = x;
        sum = term;
        for(i = 1 ; i < 10000 ; i++)
        {
                term = term * (2 * i - 1) * (2 * i - 1) * x * x / (2 * (2 * i + 1) * i);
                sum += term;
        }
        printf("asin(%f) = %f", x, sum);
        return 0;
}
