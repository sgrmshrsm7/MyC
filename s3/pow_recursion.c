//Calculating power recursion
#include <stdio.h>
long long int power(int x, int n)
{
        long long int ret_val, xpowbytwo;
        if(n==0)
        ret_val=1;
        else if(n==1)
        ret_val=x;
        else
        {
                xpowbytwo=power(x,n/2);
                ret_val=xpowbytwo*xpowbytwo;
                if(n%2==1)
                {
                        ret_val=ret_val*x;
                }
        }
        return ret_val;
}
int main()
{
        int x,n;
        printf("Enter value of x and n : ");
        scanf("%d%d",&x,&n);
        printf("pow(x,n) = %lld",power(x,n));
}
