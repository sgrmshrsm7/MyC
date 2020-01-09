//Solution of question number 5

#include <stdio.h>

void printseries()
{
        int term = 4, i;
        float multiplier = 1.5;
        for(i = 0 ; i < 7 ; ++i)
        {
                printf("%d ", term);
                term *= multiplier;
                multiplier += 0.5;
        }
}

int main()
{
        printf("Series is : ");
        printseries();
        return 0;
}
