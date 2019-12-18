//Solution of question number 3

#include <stdio.h>

int main()
{
        int n, b, i, c = 0, x;
        printf("Enter the value of b : ");
        scanf("%d", &b);
        printf("Enter the value of n : ");
        scanf("%d", &n);
        x = b;
        while(x * b <= n)
        {
                x *= b;
                c += 1;
        }
        c += 1;
        printf("Answer is : %d", c);
        return 0;
}
