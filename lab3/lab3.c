// Name: Ivan Martinez
// Compile: gcc -o a.out lab3.c
// Execute: ./a.out < file.dat
////////////////////////////////////////
////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	// Initialize Variables
	////////////////////////////////////////////////
	int n;
	scanf("%d",&n);
	double *probList = malloc( (n) * sizeof(double) );
	double L = (int)(n/2); 
	L = L/n;
	double R = 1-L;
	double temp = 0,total = 0;
	int m;
	double matrixOfProb[n][n];

	printf("probabilities sum to 1.000000\n        ");

	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &probList[i]);
		if(i < 9){printf("%d              ",i);}
		else{printf("%d             ",i);}
	}

	for(m = -1;(total+probList[m+1]) < L || ((total+probList[m+1])-L) < 0.00001;m++)
	{
		total += probList[m+1];
	}

	for(int j = 0;j < n;j++)
	{
		for(int i = 0;i < j;i++)
		{
			matrixOfProb[j][i] = 0;
		}
		for(int i = j; i < n; i++)
		{
			matrixOfProb[j][i] = probList[i];
		}
	}
	//probData(n,matrixOfProb,L,R,m);
	//printf("\nL = %lf\nR = %lf\nsplitN = %d\n",L,R,m);
	//printf("probList[%d] = %lf",0,probList[0]);
	for(int j = 0; j < n;j++)
	{
		total = 0;
		for(int i = j;i < n;i++)
		{
			if(i < m)
			{
				if(i==j)
				{
					temp = matrixOfProb[j][i];
					matrixOfProb[j][i] = 0;
				}
				else if(total+matrixOfProb[j][i] < L/2 || total+matrixOfProb[j][i]-L < 0.000001)
				{
					if(i==j+1)
					{
						matrixOfProb[j][i] += temp;
						total = matrixOfProb[j][i];
						temp = matrixOfProb[j][i];
					}
					else
					{
						matrixOfProb[j][i] += total;
						total = matrixOfProb[j][i];
						matrixOfProb[j][i]+=temp;
						temp = matrixOfProb[j][i];
					}
				}
				else
				{
						matrixOfProb[j][i] += total;
						total = matrixOfProb[j][i];
						matrixOfProb[j][i]+=temp;
						temp = matrixOfProb[j][i];
				}
			}
			else
			{
				if(i==j)
				{
					temp = matrixOfProb[j][i];
					matrixOfProb[j][i] = 0;
				}
				else
				{
					matrixOfProb[j][i] += total;
					total = matrixOfProb[j][i];
					matrixOfProb[j][i]+=temp;
					temp = matrixOfProb[j][i];
				}
			}
		}
	}

	// Print Diagrams
        ////////////////////////////////////////////////

	for(int j = 0;j < n;j++)
	{
		if(j < 10){ printf("\n  %d  ",j); }
		else{ printf("\n  %d ",j); }
		for(int i = 0;i < j;i++)
		{
			printf("-------------  ");
		}
		for(int i = j; i < n; i++)
		{
			printf("%lf    %d  ",matrixOfProb[j][i],0);
		}
	}

	printf("\n");
	// Free Memory
        ////////////////////////////////////////////////
	free(probList);
	return 0;
}

