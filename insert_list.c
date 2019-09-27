#include<stdio.h>

#define MIN_INT -32767
struct Node {
	int data;
	struct Node *next;
}*first = NULL;

void create(int item)
{
	struct Node *t,*last;

	if(first == NULL) {
		first = (struct Node*)malloc(sizeof(struct Node));
		first->data = item;
		first->next = NULL;
		last = first;
	}
	else {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = item;
		t->next = NULL;
		while(last->next!=NULL)
		last = last->next;

		last->next = t;
		//last  = t;
	
	}
}

int Max(struct Node *p)
{
	int x =0;
	if(p == 0)
		return MIN_INT;
	x = Max(p->next);
	return x > p->data ? x:p->data;
}
void Display(struct Node *p)
{
	int count;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
		count++;
	}
	printf("\n Total count of elements = %d",count);
}
void Insert(struct Node *p,int index, int x)
{	
	struct Node *t;
	int i;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if(index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}
int main()
{
//	int A[] = {10,20,30,40,50};
	create(10);
	create(20);
	create(30);
	create(40);
	create(50);
	Insert(first, 2, 5);
	Display(first);
	printf("\n Max element = %d",Max(first));
	return 0;
}
