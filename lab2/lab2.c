// Name: Ivan Martinez
// Compile: gcc -o a.out lab2.c
// Execute: ./a.out < file.dat
////////////////////////////////////////
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
int cmp(const void * a, const void * b); // function for qsort implementation using Johnson's Rule
void printSchedule(int i, int stw, int std); // Print function to display the Schedule

typedef struct basket {
	int washTime;
	int dryTime;
	int index;
} basket;
struct basket * basketList;

int main ()
{
	// Initialize Variables
	////////////////////////////////////////////////
	int n,stw,std; // n = total baskets, stw = set time wash, std = set time dry
	scanf("%d",&n);
	basketList = malloc( n * sizeof(struct basket) );
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &basketList[i].washTime);
		scanf("%d", &basketList[i].dryTime);
		basketList[i].index = i;
	}
	qsort(basketList,n,sizeof(struct basket),cmp); // sort Johnson's Rule
	stw = 0;
	std = basketList[0].washTime;

	// Schedule Task
	////////////////////////////////////////////////
	for(int i = 0; i < n; i++)
	{
		printSchedule(i,stw,std);
		if(i<n-1)
		{
			std += basketList[i].dryTime;
			stw += basketList[i].washTime;
			if(std < (basketList[i+1].washTime+stw)) // print "if" ever idle
			{
				printf("dryer gap from %d ",std);
				std += ((basketList[i+1].washTime+stw)-std);
				printf("to %d\n",std);
			}
		}
		else
		{
			std += basketList[i].dryTime;
		}
	}

	printf("makespan is: %d\n",std);

	// Release Memory
	////////////////////////////////////////////////
	free(basketList);
	return 0;
}

// Compare function for qsort implementation using Johnson's Rule
int cmp(const void* a, const void* b)
{
	// Pointers to grab values from the BasketList struct
	const basket *p1 = a;
	const basket *p2 = b;
	// Compare each wash/dry time to find smallest time for job
	// & return wether to change order or not
	if(p1->washTime < p2->dryTime)
	{
		if(p1->washTime < p1->dryTime)
		{
			if(p1->washTime < p2->washTime)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	if(p2->dryTime > p1->dryTime)
	{
		return 1;
	}
	if(p2->dryTime < p2->washTime)
	{
		return -1;
	}
	return 1;
}

// Print function to display the Schedule
// parameters(index,startTimeWash,startTimeDry);
void printSchedule(int i, int stw, int std)
{
	printf("%d %d %d %d %d\n",basketList[i].index,basketList[i].washTime,basketList[i].dryTime,stw,std);
}
