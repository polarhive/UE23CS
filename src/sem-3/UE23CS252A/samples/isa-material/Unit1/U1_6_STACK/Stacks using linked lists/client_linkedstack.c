#include "linkedstack.h"
int main()
{
	stack_t st;
	int ch, key, k;

	init(&st);
	while (1)
	{
		display(&st);
		printf("\n1..push");
		printf("\n2.pop");
		printf("\n3. display");
		printf("\n4.exit");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("enter the element..");
			scanf("%d", &key);
			push(&st, key);
			break;
		case 2:
			k = pop(&st);
			if (k > 0)
				printf("The element popped = %d\n", k);
			break;
		case 3:
			display(&st);
			break;
		case 4:
			exit(0);
		}
	}
}
