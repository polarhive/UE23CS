#define MAX 3
typedef struct arrayList
{
	int last;
	int a[MAX];	
}ARLST;

void initList(ARLST *pal);
int append(ARLST *pal,int ele);
int deleteLast(ARLST *pal,int *pele);
void display(ARLST *pal);
