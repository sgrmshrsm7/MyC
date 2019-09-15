//Calculating factorial using recursion

#include <stdio.h>

long long int fact(int n)
{
    long long int answer;
    if (n == 1)
        answer = 1;
    else
        answer = n * fact(n-1);
    return answer;
}

int main()
{
    int number;
    printf("\nEnter number : ");
    scanf("%d" , &number);
    printf("\nFactorial = %lld\n" , fact(number));
}
