// Name: Ivan Martinez
// Compile: gcc -o a.out lab1.c
// Execute: ./a.out < file.dat
////////////////////////////////////////
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RanksByMerge();
void BinarySearch();
int m, n, p, *a, *b, *aRank, *bRank, *rank, low, high;

int main() 
{
	// Initialize Variables
	////////////////////////////////////////////////
	scanf("%d %d %d",&m, &n, &p); 
	a = (int *)malloc((m+2)*sizeof(int));
	b = (int *)malloc((n+2)*sizeof(int));
	aRank = (int *)malloc((m+2)*sizeof(int));
	bRank = (int *)malloc((n+2)*sizeof(int));
	rank = (int *)malloc(p*sizeof(int));
	a[0] = -99999999, a[m+1] = 99999999;
	b[0] = -99999999, b[n+1] = 99999999;
	aRank[0] = 0, aRank[m+1] = 0;
	bRank[0] = 0, bRank[n+1] = 0;
	for(int v = 0; v < m; v++)
	{
		scanf("%d", &a[v+1]);
	}
	for(int v = 0; v < n; v++)
	{
		scanf("%d", &b[v+1]);
	}
	for(int v = 0; v < p; v++)
	{
		scanf("%d", &rank[v]);
	}
	low = 0, high = rank[0];
	RanksByMerge();	

	// Binary Search
	////////////////////////////////////////////////
	
	int i,j,k,c,lt;
	k=j=c=lt=0;
	i=(high+low)/2;
	while(k < p)
	{
		if(i+j==rank[k])
		{

				if(a[i] <= b[j] && b[j] < a[i+1])
				{
					printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",low,high,i,j,i,a[i],j,b[j],i+1,a[i+1]);
					printf("b[%d]=%d has rank %d\n",j,b[j],rank[k]);
					if((k)>=((p+1)/2))
					{
						if((k)==((p+1)/2))
						{
							lt = 0;
							if(((rank[k+1]-rank[k]) > m) || ((rank[k+1]-rank[k]) > n))
							{
								lt = lt + ((rank[k+1]-rank[k])/2);
								low = lt;
							}
							else
							{
								lt = lt + (rank[k+1]-rank[k]);
								low = lt;
							}
						}
						else
						{
							if(((rank[k+1]-rank[k]) > m) || ((rank[k+1]-rank[k]) > n))
							{
								lt = lt + ((rank[k+1]-rank[k])/2);
								low = lt;
							}
							else
							{
								lt = lt + (rank[k+1]-rank[k]);
								low = lt;
							}
						}
					}
					else
					{
						low =0;
					}
					k++;
					high = rank[k];
					if(high > m)
					{
						high = m;
					}
					else if(high > n)
					{
						high = n;
					}
				}
				else if(b[j] < a[i] && a[i] <= b[j+1])
				{
					printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",low,high,i,j,j,b[j],i,a[i],j+1,b[j+1]);
					printf("a[%d]=%d has rank %d\n",i,a[i],rank[k]);
					if((k)>=((p+1)/2)) 
					{
						if((k)==((p+1)/2))
						{
							lt = 0;
							if(((rank[k+1]-rank[k]) > m) || ((rank[k+1]-rank[k]) > n))
							{
								lt = lt + ((rank[k+1]-rank[k])/2);
								low = lt;
							}
							else
							{
								
								lt = lt + (rank[k+1]-rank[k]);
								low = lt;
							}
						}
						else
						{
							if(((rank[k+1]-rank[k]) > m) || ((rank[k+1]-rank[k]) > n))
							{
								lt = lt + ((rank[k+1]-rank[k])/2);
								low = lt;
							}
							else
							{
								lt = lt + (rank[k+1]-rank[k]);
								low = lt;
							}
						}
					}
					else
					{
						low =0;
					}
					k++; 
					high = rank[k];
					if(high > m)
					{
						high = m;
					}
					else if(high > n)
					{
						high = n;
					}
				}
				else if(i==rank[k]/2)
				{
					if(a[i] > b[j])
					{
						printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",low,high,i,j,j,b[j],i,a[i],j+1,b[j+1]);
						c = a[i];
						high=i-1;
					}
					else 
					{
						printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",low,high,i,j,i,a[i],j,b[j],i+1,a[i+1]);
						c = b[j];						
						low = i+1;
					}
				}
				else
				{
					if((a[i]-c) <= (b[j]-c))
					{
						printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",low,high,i,j,i,a[i],j,b[j],i+1,a[i+1]);					
						low = i+1;
					}
					else 
					{
						printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",low,high,i,j,j,b[j],i,a[i],j+1,b[j+1]);
						high=i-1;
					}
					
				}
			i=(high+low)/2;
			j=0;			
		}
		else
		{
			j++;
		}
	}

	// Release Memory
	///////////////////////////////////////////////////
	free(a);
	free(b);
	free(aRank);
	free(bRank);
	free(rank);
	return 0;
}

void RanksByMerge()
{
	int i,j,k;
	i=j=k=1;
	while(i<=m && j<=n)
	{
		if(a[i]<=b[j])
		{
			aRank[i++]=k++;
		}
		else
		{
			bRank[j++]=k++;
		}
	}
	while(i<=m)
	{
		aRank[i++]=k++;
	}
	while(j<=n)
	{
		bRank[j++]=k++;
	}	
}
