//Calculating greatest integer function(floor) of log of a on base b

#include <stdio.h>

int main()
{
    int a,b,i,term;
    printf("Enter values of a and b : ");
    scanf("%d%d",&a,&b);
    term = 1;
    for (i = 0 ; term <= a; i++)
    {
        term *= b;
    }
    i--;
    printf("Answer is : %d",i);
}
