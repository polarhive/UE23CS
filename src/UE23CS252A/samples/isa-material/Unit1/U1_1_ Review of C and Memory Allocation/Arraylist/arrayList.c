#include<stdio.h>
#include"arrayList.h"

int main()
{
	ARLST al;

	initList(&al);	//List is initialized to be empty

	int choice,ele,status;

	printf("1.InsertEnd 2.DeleteEnd 3.Display\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					status=append(&al,ele);
					if(status)
						printf("%d inserted successfully\n",ele);
					else
						printf("List is already full\n");
					break;
			case 2: status=deleteLast(&al,&ele);
					if(status)
						printf("%d deleted successfully\n",ele);
					else
						printf("List is already empty\n");
					break;
			case 3: display(&al);
					break;
		}
		printf("1.InsertEnd 2.DeleteEnd 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
}