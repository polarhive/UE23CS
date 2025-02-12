//Program to demo round robin scheduling

#include<stdio.h>  
  
void main()  
{  
    int i, n, sum = 0, count=0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    
    printf("Enter the total number of process to schedule: ");  
    scanf("%d", &n);  
    y = n; // Assign the number of process to variable y  
  
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for (i = 0; i < n; i++)  
    {  
        printf("\n Enter the Arrival and Burst time of the Process[%d]: ", i+1);  
        scanf("%d %d", &at[i], &bt[i]);  
        temp[i] = bt[i]; // temp[] stores remaining burst time, which reduces after execution  
    }  

    // Accept the Time quantum  
    printf("Enter the Time Quantum for the process: ");  
    scanf("%d", &quant);  

    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\nProcess No\t\tBurst Time\t\tTAT\t\tWaiting Time ");  

    for (sum = 0, i = 0; y != 0; )   //sum = 0; → Keeps track of the current execution time, i = 0; → Starts with the first process.
                                                  //y != 0; → Ensures the loop continues until all processes complete (y tracks remaining processes).
    {  
       if (temp[i] <= quant && temp[i] > 0) // // If remaining time is ≤ quantum
       {  
          sum = sum + temp[i];  // Add remaining burst time  
          temp[i] = 0;  // Process finishes execution 
          count=1;   //marks process completion.
       }     
       else if(temp[i] > 0)    //If Process Needs More Time
      {  
          temp[i] = temp[i] - quant;   // Reduce burst time by quantum  
          sum = sum + quant;    // Add quantum to total execution time 
       }  
    
       if(temp[i]==0 && count==1)  //If a Process Completes Execution
       {  
          y--; //decrement the process no.  
          printf("\nProcess No[%d]\t\t%d\t\t\t%d\t\t\t%d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
          wt = wt+sum-at[i]-bt[i];  
          tat = tat+sum-at[i];  
          count =0;     
       }  

       if (i == n-1)  //Moving to the Next Process

          i=0;   // Restart cycle when reaching last process  
       else if (at[i+1] <= sum)  
          i++;  // Move to next process if it has arrived  
       else  
          i=0;  // If the next process hasn’t arrived, restart from the first process  
    }

    // represents the average waiting time and Turn Around time  
    avg_wt = (float)wt/n;  
    avg_tat = (float)tat/n;
  
    printf("\nAverage Turn Around Time: %f", avg_tat);  
    printf("\nAverage Waiting Time: %f\n", avg_wt);    
}  