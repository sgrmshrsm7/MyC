//Calculating GCD of two numbers

#include <stdio.h>

int gcd(int a, int b)
{
    int ans;
    if (a % b == 0)
    {
        ans = b;
    }
    else
    {
        ans = gcd(b,a % b);
    }
    return ans;
}

int main()
{
    int a,b;
    printf("Enter two numbers : ");
    scanf("%d%d",&a,&b);
    printf("GCD is : %d" , gcd(a,b));
    return 0;
}
