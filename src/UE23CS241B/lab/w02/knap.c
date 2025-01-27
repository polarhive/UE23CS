#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *Solve(int tasks_in_job[], int payment_for_job[], int total_jobs, int max_tasks)
{
    int max_wage = 0;                 // To track the maximum wage achieved
    int max_tasks_used = 0;           // To track the corresponding number of tasks used
    int subsets = pow(2, total_jobs); // Total number of subsets (2^total_jobs)

    for (int subset = 0; subset < subsets; subset++)
    {
        int current_tasks = 0;
        int current_wage = 0;

        for (int i = 0; i < total_jobs; i++)
        {
            if (subset & (1 << i))
            {
                current_tasks += tasks_in_job[i];
                current_wage += payment_for_job[i];
            }
        }

        if (current_tasks <= max_tasks && current_wage > max_wage)
        {
            max_wage = current_wage;
            max_tasks_used = current_tasks;
        }
    }

    int *result = malloc(2 * sizeof(int));
    result[0] = max_tasks_used; // Total tasks used for maximum wage
    result[1] = max_wage;       // Maximum wage achieved

    return result;
}

int main()
{
    int total_jobs; // Number of available jobs
    scanf("%d", &total_jobs);

    int *tasks_in_job = (int *)malloc(total_jobs * sizeof(int));
    int *payment_for_job = (int *)malloc(total_jobs * sizeof(int));
    int max_tasks; // Maximum allowable tasks

    for (int i = 0; i < total_jobs; i++)
    {
        scanf("%d", &tasks_in_job[i]);
    }

    for (int i = 0; i < total_jobs; i++)
    {
        scanf("%d", &payment_for_job[i]);
    }
    scanf("%d", &max_tasks);
    int *result = Solve(tasks_in_job, payment_for_job, total_jobs, max_tasks);
    printf("%d %d", result[0], result[1]);
    free(tasks_in_job);
    free(payment_for_job);
    free(result);

    return 0;
}
