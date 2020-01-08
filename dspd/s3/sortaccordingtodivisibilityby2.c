// Sort array such that all even numbers come before odd numbers. Order of even numbers and odd numbers remains same.
// For example : [3, 2, 9, 1, 46, 22] will become [2, 46, 22, 3, 9, 1] 

#include <stdio.h>

int main()
{
	int n,i,j,s,temp;
	printf("Enter number of elements in the array : ");
	scanf("%d",&n);
	int A[n];
	printf("Enter elements of the array : ");
	for(i = 0;i < n;i++)
		scanf("%d",&A[i]);
	s = 1;
	for(i = 0;i < n && s == 1; i++)
	{
		s = 0;
		for(j = 0;j < n-1-i;j++)
		{
			if((A[j]%2!=0) && (A[j+1]%2==0))
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				s = 1;
			}
		}
	}
	printf("Result array is : ");
	for(i = 0;i < n;i++)
		printf("%d ",A[i]);
	return 0;
}
