//Calculating squareroot of a number without using math library

#include <stdio.h>

double fabsolute(double n)
{
    double ans;
    if (n > 0) {
        ans = n;
    }
    else {
        ans = -1 * n;
    }
}

double squareroot(double n, double err)
{
    double sqrroot = n / 2.0 , s = 2;
    while(fabsolute(n - sqrroot * sqrroot) > err)
    {
        sqrroot = (sqrroot + s) / 2;
        s = n / sqrroot;
    }
    return sqrroot;
}

int main()
{
    double number , root;
    double error;
    printf("\nEnter number : ");
    scanf("%lf", &number);
    printf("Enter upto what error to calculate sqrt(eg : 0.001 or 0) : ");
    scanf("%lf", &error);
    root = squareroot(number , error);
    if((int)(root) == root)
        printf("%d", (int)(root));
    else
        printf("\nSquareRoot of the number is : %lf\n", root);
    return 0;
}
