// Program to demonstrate "Shortest Remaining Time First" CPU scheduling

#include <stdio.h>

int main() 
{
    int a[10],b[10],x[10];     //b[10] for remaining burst time , x[10] original burst time
    int i,j,smallest,count=0,time,n;
    int waiting[10], turnaround[10], completion[10];
    double avg=0,tt=0,end;
    char pn[10][10];

    printf("Enter the number of processes to schedule:\n");
    scanf("%d",&n); 

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, arrival time and burst time for each process:\n");
        scanf("%s %d %d", pn[i], &a[i], &b[i]);
    }

    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[9]=9999;
		       
    for (time = 0; count != n; time++)
    {
        smallest = 9;

        for (i = 0; i < n; i++)
        {
           if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)   //Has the process arrived? (a[i] <= time)
                                                                                        //Is its burst time smaller than the currently selected smallest       																																				process? (b[i] < b[smallest])
                                                                                        //Is the process still running (not completed)? (b[i] > 0
              smallest = i;
        }

        b[smallest]--;              //selected process executes for 1 unit of time, so its burst time decreases

	if (b[smallest] == 0)   //process has finished execution
        {
           count++;       //One more process is completed
           end = time + 1;  // Mark completion time,time starts from 0
	   completion[smallest] = end;
	   waiting[smallest] = end - a[smallest] - x[smallest];
	   turnaround[smallest] = end - a[smallest];
        }
     }

     printf("Process\tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletion-time\n");
     printf("-------\t----------\t------------\t------------\t---------------\t---------------\n");

     for (i = 0; i < n; i++)
     {
         printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pn[i], x[i], a[i], waiting[i], turnaround[i], completion[i]);
         avg = avg + waiting[i];
         tt = tt + turnaround[i];
     }

     printf("\n\nAverage waiting time = %lf\n", (float)avg/n);
     printf("Average Turnaround time = %lf\n", (float)tt/n);

     return 0;
}