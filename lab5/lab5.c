// Name: Ivan Martinez
// Compile: gcc -o a.out lab5.c
// Execute: ./a.out < file.dat
////////////////////////////////////////
////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct vertLinkedList {
	int x;
	int y;
	struct vertLinkedList *nextForward;
	struct vertLinkedList *nextBack;
} vertlist;
struct vertLinkedList *head;

int main ()
{
	// Initialize Variables
	////////////////////////////////////////////////
	head = (struct vertLinkedList*)malloc(sizeof(struct vertLinkedList));
	struct vertLinkedList *tail, *temp = head;
	int n, c = 0, *pebbleList;
	char checkEnd;
	scanf("%d",&n); // Grab n
	printf("%d\n",n);
	while(scanf("%c", &checkEnd) != EOF) // Loop until end of dat file
	{
		tail = (struct vertLinkedList*)malloc(sizeof(struct vertLinkedList));
		scanf("%d", &tail->x); // Grab x
		scanf("%d", &tail->y); // Grab y
		tail ->nextForward = NULL;
		temp ->nextForward = tail;
		tail ->nextBack = temp;
        	temp = tail;
		printf("%d %d\n",tail->x,tail->y);
		c++;
	}
	pebbleList = malloc( c * sizeof(int) );
	for(int i = 0; i < c;i++)
	{
		pebbleList[i] = 2;
	}
	temp = head; // Initialize Head to first struct under the LinkedList
	temp = temp->nextForward;
	free(head);
	head = temp;	
	
	// Pebble Game
	////////////////////////////////////////////////

	
	for(int i = 0; i  < c; i++ )
	{
		pebbleList[temp->x]--;
		pebbleList[temp->y]++;
		temp = temp->nextForward;
	}
	printf("=========\n");
	for(int i = 0; i < n;i++)
	{
		printf("%d has %dv\n",i,pebbleList[i]);
	}



	printf("Laman\n");
	//printf("redundant\n");

	// Release Memory
	////////////////////////////////////////////////
	temp = head;
	while(temp->nextForward != NULL)
	{
		temp=temp->nextForward;
		free(temp->nextBack);
	}
	free(temp);
	return 0;
}

