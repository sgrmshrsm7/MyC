//Adding two polynomials

#include <stdio.h>

int main()
{
        int n, m;
        printf("Enter highest power of Polynomial 1 : ");
        scanf("%d", &n);
        printf("Enter highest power of Polynomial 2 : ");
        scanf("%d", &m);
        n++;
        m++;
        int a[n], b[m], max, i;
        if (m > n)
                max = m;
        else max = n;
        int c[max];
        printf("Enter coefficients of Polynomial 1 :-\n");
        for(i = 0 ; i < max ; i++)
        {
                if(i < n)
                {
                        printf("Polynomial 1 power %d : ", i);
                        scanf("%d", &a[i]);
                        c[i] = a[i];
                }
                else c[i] = 0;
        }
        printf("Enter coefficients of Polynomial 2 :-\n");
        for(i = 0 ; i < m ; i++)
        {
                printf("Polynomial 2 power %d : ", i);
                scanf("%d", &b[i]);
                c[i] += b[i];
        }
        printf("\nPolynomial 1 is : ");
        for(i = n - 1 ; i >= 0 ; i--)
                printf(" %dx^%d +", a[i], i);
        printf("\b ");
        printf("\nPolynomial 2 is : ");
        for(i = m - 1 ; i >= 0 ; i--)
                printf(" %dx^%d +", b[i], i);
        printf("\b ");
        printf("\nAddition is : ");
        for(i = max - 1 ; i >= 0 ; i--)
                printf(" %dx^%d +", c[i], i);
        printf("\b");
        return 0;
}
