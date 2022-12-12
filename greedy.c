#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
int a[100][100],i,j,visited[100],n=100,cost = 0;
void takeInput(int n)
{
    printf("Enter cost values \n");
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    if(i==j)
	    a[i][j] = INT_MAX;
	    else
	    a[i][j] = rand() %100;
	}
    }
    visited[0] = 1;
}
void findmin(int c)
{
    int low = INT_MAX,k=0,flag;
    printf("%d -- ",c+1);
    for(i=0;i<n;i++)
    {
	if(c==i)
	{
		continue;
	}
	if(a[c][i] <low && visited[i] !=1)
	{
	    low = a[c][i];
	    k=i;
	    cost+=low;
	}
    }
    visited[k] = 1;
    printf( "%d \n",k+1);
    flag = allchecked(n);
    if(flag == 1)
    {
	findmin(k);
    }
    else
    {
        printf("%d -- 1 \n", k+1);
        cost+=a[k][0];
    }
}
int allchecked()
{
    int f=0;
    for(i=0;i<n;i++)
    {
	if(visited[i] != 1)
	f=1;
    }
    return f;
}
void writetoFile(double time)
{
    FILE *f;
    f  = fopen("greedydata.txt","a");
    fprintf(f,"%f \n",time);
    fclose(f);
}
int main()
{
    clock_t start, end;
    double time;
    
    takeInput(n);
        printf("Path is ");
        start = clock();
        findmin(0);
        printf("Cost is %d \n", cost);
        end= clock();
        time= (double)(end-start )/CLOCKS_PER_SEC;
        writetoFile(time*1000);
        printf("Execution time : %lf", time);
    return 0;
}
