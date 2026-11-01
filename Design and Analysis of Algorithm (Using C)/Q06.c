//Implement job sequencing with deadlines Problem using appropriate algorithm design technique in C
//Source Code:

#include <stdio.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

int main()
{
    int n, i, j, maxDeadline = 0;
    int slot[100] = {0};
    int totalProfit = 0;

    struct Job job[100], temp;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter deadline and profit of each job:\n");

    for (i = 0; i < n; i++)
    {
        job[i].id = i + 1;
        scanf("%d %d", &job[i].deadline, &job[i].profit);

        if (job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (job[i].profit < job[j].profit)
            {
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = job[i].deadline; j > 0; j--)
        {
            if (j <= maxDeadline && slot[j] == 0)
            {
                slot[j] = job[i].id;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs:\n");

    for (i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] != 0)
            printf("Job %d ", slot[i]);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}
