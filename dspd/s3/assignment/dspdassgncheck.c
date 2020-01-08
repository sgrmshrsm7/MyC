#include <stdio.h>
#include <math.h>
#define daysinamonth 4

int main()
{
        int n;
        printf("Enter number of stations(n) : ");
        scanf("%d", &n);

        //Defining structure
        struct climatestation {
                float skyviewfactor;
                float vegetationdensity;
                float populationdensity;
                int pervioussurface;
                int impervioussurface;
                char status;
                float distancefromstations[n];
                float airtemperature[daysinamonth];
                float relativehumidity[daysinamonth];
        };

        struct climatestation A[n];
        int i, j, k, count, qno, temp;

        //Taking input from the user
        for(i = 0 ; i < n ; i++)
        {
                printf("Enter sky view factor(from 0.1 to 0.9) of climatestation no. %d : ", i + 1);
                scanf("%f", &A[i].skyviewfactor);
                printf("Enter vegetation density ratio(percentage) of climatestation no. %d : ", i + 1);
                scanf("%f", &A[i].vegetationdensity);
                printf("Enter populationdensity(per sq. km) of climatestation no. %d : ", i + 1);
                scanf("%f", &A[i].populationdensity);
                printf("Enter pervious surface fraction(integer from 0 to 15) of climatestation no. %d : ", i + 1);
                scanf("%d", &A[i].pervioussurface);
                printf("Enter impervious surface fraction(integer from 0 to 15) of climatestation no. %d : ", i + 1);
                scanf("%d", &A[i].impervioussurface);
                printf("Enter status('U' for urban and 'R' for rural) of climatestation no. %d : ", i + 1);
                scanf(" %c", &A[i].status);
                for(j = 0 ; j < n ; j++)
                {
                        if(i < j)
                        {
                                printf("Enter distance(km) of station %d from station %d : ", i + 1, j + 1);
                                scanf("%f", &A[i].distancefromstations[j]);
                        }
                        else if(i == j)
                                A[i].distancefromstations[j] = 0;
                        else A[i].distancefromstations[j] = A[j].distancefromstations[i];
                }
                for(j = 0 ; j < daysinamonth ; j++)
                {
                        printf("Enter air temperature(Celsius) of climatestation no. %d on day %d: ", i + 1, j + 1);
                        scanf("%f", &A[i].airtemperature[j]);
                }
                for(j = 0 ; j < daysinamonth ; j++)
                {
                        printf("Enter relative humidity of climatestation no. %d on day %d: ", i + 1, j + 1);
                        scanf("%f", &A[i].relativehumidity[j]);
                }
        }

        int avgcitytemp = 0, highesttemp[n], highesttemppos[n]; //variables for question 1
        int stanum, nearestrstation, mintempdiff; //variables for question 2
        struct climatestation Atemp[n], tempstruct; //variables for question 3 & 4
        int sort, Atempaddr[n];

        void heatislandintensity(struct climatestation A[], int size)
        {
                int i, j, nearestrstation;
                float hii;
                for(j = 0 ; j < size ; j++)
                {
                        if(A[j].status == 'U')
                        {
                                //Finding nearest rural station
                                count = 0;
                                nearestrstation = j;
                                for(i = 0 ; i < n ; i++)
                                {
                                        if(A[i].status == 'R')
                                        {
                                                if(count == 0)
                                                {
                                                        nearestrstation = i;
                                                        count++;
                                                }
                                                else if(A[j].distancefromstations[nearestrstation] > A[j].distancefromstations[i])
                                                        nearestrstation = i;
                                                else if(A[j].distancefromstations[nearestrstation] == A[j].distancefromstations[i] && A[i].pervioussurface > A[nearestrstation].pervioussurface)
                                                        nearestrstation = i;
                                        }
                                }
                                hii = 0;
                                if(nearestrstation == j)
                                        printf("\nNo rural station!");
                                else
                                {
                                        for(i = 0 ; i < daysinamonth ; i++)
                                        {
                                                hii = hii + A[j].airtemperature[i] - A[nearestrstation].airtemperature[i];
                                        }
                                        hii = hii / daysinamonth;
                                        printf("\nHighest island intensity for station %d is : %f", j + 1, hii);
                                }
                        }
                }
        }

        //Calculating average city temperature
                for(i = 0 ; i < n ; i++)
                        for(j = 0 ; j < daysinamonth ; j++)
                        {
                                avgcitytemp = avgcitytemp + A[i].airtemperature[j];
                        }
                avgcitytemp = avgcitytemp / (daysinamonth * n);
        qno=0;
        while(qno!=6)
        {
        printf("Enter question number to run(Enter 6 for exit) : ");
        scanf("%d", &qno);
        switch(qno)
        {
                case 1: //Calculating highest temperature and its day number for each station
                        for(i = 0 ; i < n ; i++)
                        {
                                highesttemp[i] = A[i].airtemperature[0];
                                highesttemppos[i] = 0;
                                for(j = 1 ; j < daysinamonth ; j++)
                                {
                                        if(A[i].airtemperature[j] > highesttemp[i])
                                        {
                                                highesttemp[i] = A[i].airtemperature[j];
                                                highesttemppos[i] = j;
                                        }
                                }
                        }

                        //Checking whether highest temperature is a heat degree day
                        for(i = 0 ; i < n ; i++)
                        {
                                printf("\nHighest heat degree day for station %d is : ", i + 1);
                                if (highesttemp[i] > avgcitytemp)
                                        printf("On day %d", highesttemppos[i] + 1);
                                else printf("No heat degree day for this station");
                        }
                        break;
                case 2: printf("\nEnter the station number for which thermally comfortable days are to be calculated : ");
                        scanf("%d", &stanum);
                        stanum--;
                        if(A[stanum].status == 'R')
                                printf("You have entered rural station number!");
                        else
                        {
                                //Finding nearest rural station
                                count = 0;
                                nearestrstation = stanum;
                                for(i = 0 ; i < n ; i++)
                                {
                                        if(A[i].status == 'R')
                                        {
                                                if(count == 0)
                                                {
                                                        nearestrstation = i;
                                                        count++;
                                                }
                                                else if(A[stanum].distancefromstations[nearestrstation] > A[stanum].distancefromstations[i])
                                                        nearestrstation = i;
                                        }
                                }

                                mintempdiff = fabs(A[stanum].airtemperature[0] - A[nearestrstation].airtemperature[0]);
                                count = 1;
                                for(i = 1 ; i < daysinamonth ; i++)
                                {
                                        if(fabs(A[stanum].airtemperature[i] - A[nearestrstation].airtemperature[i]) < mintempdiff)
                                        {
                                                mintempdiff = fabs(A[stanum].airtemperature[i] - A[nearestrstation].airtemperature[i]);
                                                count = 1;
                                        }
                                        else if(fabs(A[stanum].airtemperature[i] - A[nearestrstation].airtemperature[i]) == mintempdiff)
                                                count++;
                                }
                                printf("\nThermally comfortable days are : ");
                                for(i = 0 ; i < daysinamonth && count > 0; i++)
                                        if(fabs(A[stanum].airtemperature[i] - A[nearestrstation].airtemperature[i]) == mintempdiff)
                                        {
                                                printf("%d ", i + 1);
                                                count--;
                                        }
                        }
                        break;
                case 3: //Creating Atemp = A
                        for(i = 0 ; i < n ; i++)
                        {
                                Atemp[i] = A[i];
                        }

                        //Sorting according to vegetation density ratio
                        sort = 1;
                        for(i = 0 ; i < n && sort == 1 ; i++)
                        {
                                sort = 0;
                                for(j = 0 ; j < n - i - 1 ; j++)
                                {
                                        if(Atemp[j].vegetationdensity < Atemp[j + 1].vegetationdensity)
                                        {
                                                tempstruct = Atemp[j];
                                                Atemp[j] = Atemp[j + 1];
                                                Atemp[j + 1] = tempstruct;
                                                sort = 1;
                                        }
                                }
                        }

                        for(i = 0 ; i < n ; i++)
                        {
                                printf("\nDays for station %d(New Position) are : ", i + 1);
                                count = 0;
                                for(j = 0 ; j < daysinamonth ; j++)
                                {
                                        if(Atemp[i].airtemperature[j] > avgcitytemp)
                                        {
                                                printf("%d ", j + 1);
                                                count++;
                                        }
                                }
                                if(count == 0)
                                        printf("No such day for this station");
                        }
                        break;
                case 4: //Creating Atemp = A
                        for(i = 0 ; i < n ; i++)
                        {
                                Atemp[i] = A[i];
                        }

                        //Storing initial sequence
                        for(i = 0 ; i < n ; i++)
                                Atempaddr[i] = i;

                        //Calculating highest temperature and its day number for each station
                        for(i = 0 ; i < n ; i++)
                        {
                                highesttemp[i] = Atemp[i].airtemperature[0];
                                for(j = 1 ; j < daysinamonth ; j++)
                                {
                                        if(Atemp[i].airtemperature[j] > highesttemp[i])
                                        {
                                                highesttemp[i] = Atemp[i].airtemperature[j];
                                        }
                                }
                        }

                        //Sorting according to population density
                        sort = 1;
                        for(i = 0 ; i < n && sort == 1 ; i++)
                        {
                                sort = 0;
                                for(j = 0 ; j < n - i - 1 ; j++)
                                {
                                        if(Atemp[j].populationdensity > Atemp[j + 1].populationdensity)
                                        {
                                                temp = highesttemp[j];
                                                highesttemp[j] = highesttemp[j + 1];
                                                highesttemp[j + 1] = temp;
                                                tempstruct = Atemp[j];
                                                Atemp[j] = Atemp[j + 1];
                                                Atemp[j + 1] = tempstruct;
                                                temp = Atempaddr[j];
                                                Atempaddr[j] = Atempaddr[j + 1];
                                                Atempaddr[j + 1] = temp;
                                                sort = 1;
                                        }
                                        else if(Atemp[j].populationdensity == Atemp[j + 1].populationdensity && highesttemp[j] < highesttemp[j + 1])
                                        {
                                                temp = highesttemp[j];
                                                highesttemp[j] = highesttemp[j + 1];
                                                highesttemp[j + 1] = temp;
                                                tempstruct = Atemp[j];
                                                Atemp[j] = Atemp[j + 1];
                                                Atemp[j + 1] = tempstruct;
                                                temp = Atempaddr[j];
                                                Atempaddr[j] = Atempaddr[j + 1];
                                                Atempaddr[j + 1] = temp;
                                                sort = 1;
                                        }
                                }
                        }

                        printf("\nEnter the value of k : ");
                        scanf("%d", &k);
                        printf("\nStations in order are : ");
                        for(i = 0 ; i < k ; i++)
                                printf("%d ", Atempaddr[i] + 1);
                        break;
                case 5: heatislandintensity(A, n);
                        break;
                case 6: printf("Program Exiting...");
                        break;
                default: printf("Invalid question number!!!");
        }
        }
        return 0;
}
