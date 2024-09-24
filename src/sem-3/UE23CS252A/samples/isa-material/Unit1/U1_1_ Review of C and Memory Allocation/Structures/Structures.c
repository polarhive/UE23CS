// Structures - User Defined Data Type - Heterogeneous collection of data elements
/*#include<stdio.h>
#include<string.h>
struct student
{
	int rollno;
	char name[20];
	int marks;
};
int main()
{
	struct student s1;*/
	/*printf("Size of structure is %ld\n",sizeof(struct student));
	s1.rollno=1;
	s1.rollno=3;
	printf("Roll no of student is %d\n",s1.rollno);
	//s1.name="Ram";
	strcpy(s1.name,"Ram");
	printf("name of student is %s\n",s1.name);
	//printf("Size of structure is %ld\n",sizeof(struct student));
	s1.marks=90;
	printf("Marks of student is %d\n",s1.marks);*/

	/*struct student s2={.name="RAM",.marks=90, .rollno=90};
	printf("Roll no of student is %d\n",s2.rollno);
	printf("name of student is %s\n",s2.name);
	printf("Marks of student is %d\n",s2.marks);
	
	return 0;}	*/
//#include<stdio.h>
//#pragma pack(1)
/*struct a
{
	int a;//4
	int b;//4
	char c;//1 - 9
};

struct b
{
	int d;//4
	char e;//1 - 5
};

struct c
{
	int f;//4
	float g;//4
	char h;//1
	int i;//4 - 13

};
int main()
{
	printf("%ld\n", sizeof(struct a));
	printf("%ld\n", sizeof(struct b));
	printf("%ld\n", sizeof(struct c));

	return 0;
}
*/
#include<stdio.h>
struct test
{
	int a;
	char b;
};

int main()
{
	struct test t1={1,'a'};
	struct test t2=t1;
	printf("%d\t %c\t", t1.a,t1.b);
	printf("\n");
	printf("%d\t %c\t", t2.a,t2.b);
	t2.b='p';
	printf("%d\t %c\t", t1.a,t1.b);
	printf("\n");
	printf("%d\t %c\t", t2.a,t2.b);
	t1.b='c';
	printf("%d\t %c\t", t1.a,t1.b);
	printf("\n");
	printf("%d\t %c\t", t2.a,t2.b);
	return 0;
}
















































