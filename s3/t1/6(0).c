//Solution of question number 6

#include <stdio.h>

int main()
{
        int n, i, term = 1, sum = 1;
        printf("Enter the value of n : ");
        scanf("%d", &n);
        for(i = 0 ; i < n ; i++)
        {
                printf("%d ", term);
                term = sum + 1;
                sum = sum + term;
        }
        return 0;
}
