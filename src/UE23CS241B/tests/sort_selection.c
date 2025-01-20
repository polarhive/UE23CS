#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void display(int array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void selectionSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		swap(&array[minIndex], &array[i]);
	}
}

int main()
{
	int data[] = {64, 34, 25, 12, 22, 11, 90, 78, 56, 43};
	int n = sizeof(data) / sizeof(data[0]);

	printf("Original:\n");
	display(data, n);

	clock_t start = clock();
	selectionSort(data, n);
	clock_t end = clock();

	printf("Selection Sorted:\n");
	display(data, n);

	double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for sorting: %.6f seconds\n", timeTaken);

	return 0;
}
