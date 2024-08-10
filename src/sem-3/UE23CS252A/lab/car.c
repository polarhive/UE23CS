#include <stdio.h>

struct Car
{
    int carID;
    char model[50];
    float rentalRate;
};

int main()
{
    struct Car cars[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &cars[i].carID);
        scanf("%s", cars[i].model);
        scanf("%f", &cars[i].rentalRate);
    }

    int numDays;
    scanf("%d", &numDays);

    for (int i = 0; i < 3; i++)
    {
        float totalCost = cars[i].rentalRate * numDays;
        printf("Total Rental Cost for Car %d: %.2f\n", i + 1, totalCost);
    }

    return 0;
}
