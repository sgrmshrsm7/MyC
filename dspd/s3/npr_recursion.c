//Calulate nPr(Permutation) using recursion

#include <stdio.h>
int N;
int nPr(int n, int r)
{
	int ans;
	if(N-r>0)
		ans = (n)*(nPr(n-1,r+1))/(N-r);
	else if(n>0)
		ans = n*(nPr(n-1,r));
	else ans=1;
	return ans;
}
int main()
{
	int n,r;
	printf("Enter values of n & r : ");
	scanf("%d%d",&n,&r);
	N=n;
	printf("nPr is : %d",(nPr(n,r)));
	return 0;
}
