//Find third largest number and it's frequency in the array.

#include <stdio.h>
#include <limits.h>

int main()
{
        int n, i, first, firstfreq, second, secondfreq, third, thirdfreq;
        printf("Enter number of elements in the array : ");
        scanf("%d", &n);
        int a[n];
        printf("Enter %d elements for the array : ", n);
        for(i = 0 ; i < n ; i++)
                scanf("%d", &a[i]);
        first = INT_MIN;
        firstfreq = 1;
        second = INT_MIN;
        secondfreq = 1;
        third = INT_MIN;
        thirdfreq = 1;
        for(i = 0 ; i < n ; i++)
        {
                if(a[i] > first)
                {
                        third = second;
                        thirdfreq = secondfreq;
                        second = first;
                        secondfreq = secondfreq;
                        first = a[i];
                        firstfreq = 1;
                }
                else if(a[i] == first)
                        firstfreq++;
                else if(a[i] > second)
                {
                        third = second;
                        thirdfreq = secondfreq;
                        second = a[i];
                        secondfreq = 1;
                }
                else if(a[i] == second)
                        secondfreq++;
                else if(a[i] > third)
                {
                        third = a[i];
                        thirdfreq = 1;
                }
                else if(a[i] == third)
                        thirdfreq++;
        }
        if(third == second)
                printf("\nThird highest does not exist");
        else printf("\nThird highest is : %d\nAnd it's frequency is : %d", third, thirdfreq);
        return 0;
}
