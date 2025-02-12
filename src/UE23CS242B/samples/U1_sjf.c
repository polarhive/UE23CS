//Program to demo "Shortest Job First" CPU scheduling

#include <stdio.h>
#include <string.h>

void main()
{
    int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];     //execution time, arrival time,start time,finish time,waiting time,turnaround time
    int totwt = 0, totta = 0;   //total waiting time and total turnaround time
    float awt, ata;      //average waiting time and average turnaround time.
    char pn[10][10], t[10];   //process name and Temporary variable used for swapping process names.
			    
    printf("Enter the number of processes to schedule:");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, arrival time and execution time of each process:");
        scanf("%s %d %d", pn[i], &at[i], &et[i]);
    }

    for (i = 0; i < n; i++)          //Sorting Processes Based on Execution Time (SJF Sorting)
        for (j = 0; j < n; j++)
        {
            if (et[i] < et[j])         //Swaps execution time (et[]), arrival time (at[]), and process name (pn[]).
            {
	        temp = at[i];
	        at[i] = at[j];
	        at[j] = temp;
	        temp = et[i];
	        et[i] = et[j];
	        et[j] = temp;
	        strcpy(t, pn[i]);
	        strcpy(pn[i], pn[j]);
	        strcpy(pn[j], t);
	    }
	}

    for (i = 0; i < n; i++)    //Calculating Start Time, Waiting Time, and Completion Time

    {
        if (i == 0)
	   st[i] = at[i];        //First process starts at its arrival time
        else
           st[i] = ft[i-1];    // Next process starts after the previous one finishes

	wt[i] = st[i] - at[i];  // Waiting Time
	ft[i] = st[i] + et[i];  // Completion Time
	ta[i] = ft[i] - at[i];  // Turnaround Time
	totwt += wt[i];
	totta += ta[i];
    }

    awt = (float)totwt/n;
    ata = (float)totta/n;

    printf("\nProcess\tArrivalTime\tExecutionTime\tWaitingTime\tTurnAroundTime");
    printf("\n-------\t-----------\t-------------\t-----------\t--------------");

    for (i = 0; i < n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]);

    printf("\nAverage waiting time is: %f", awt);
    printf("\nAverage turnaround time is: %f\n", ata);
}