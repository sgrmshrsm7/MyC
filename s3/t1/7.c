//Solution of question number 7

#include <stdio.h>

int main()
{
        int term = 1, sum = 1, n, i;
        printf("Enter the value of n : ");
        scanf("%d", &n);
        for(i = 1 ; i < n ; ++i)
        {
                term += (2 * i + 1);
                sum += term;
        }
        printf("Sum of the series = %d", sum);
        return 0;
}
