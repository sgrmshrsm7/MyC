//Solution of question number 4

#include <stdio.h>

int main()
{
        int n, d, steps = 0, num = 0, powof2 = 1;
        printf("Enter the value of n : ");
        scanf("%d", &n);
        printf("Enter the value of d : ");
        scanf("%d", &d);
        while(num % n != d)
        {
                num += powof2;
                powof2 = powof2<<1;
                steps += 1;
        }
        printf("Number of steps = %d", steps);
        return 0;
}
