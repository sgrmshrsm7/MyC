// Print following series using recursion :
// 1 2 3 ... (n-1) n (n-1) ... 3 2 1

#include <stdio.h>

int N;

void printseries(int n)
{
	if(n==1)
		printf("%d ",N);
	else {
		printf("%d ",N-n+1);
		printseries(n-1);
		printf("%d ",N-n+1);
	}
}

int main()
{
	int n;
	printf("Enter value of n : ");
	scanf("%d",&n);
	N = n;
	printseries(n);
    return 0;
}
