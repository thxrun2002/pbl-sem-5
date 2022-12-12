#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ary[100][100],completed[100],n=3,cost=0;
void takeInput()
{
int i,j;
printf("\nEnter the Cost Matrix\n");
 
for(i=0;i < n;i++)
{
printf("\nEnter Elements of Row: %d\n",i+1);
 
for( j=0;j < n;j++)
{
    if(i==j)
    ary[i][j] = 0;
    else
    ary[i][j] = rand() %100;
}
 
completed[i]=0;
}
 
printf("\n\nThe cost list is:");
 
for( i=0;i < n;i++)
{
printf("\n");
 
for(j=0;j < n;j++)
printf("\t%d",ary[i][j]);
}
}
 
void mincost(int city)
{
int i,ncity;
 
completed[city]=1;
 
printf("%d--->",city+1);
ncity=least(city);
 
if(ncity==999)
{
ncity=0;
printf("%d",ncity+1);
cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity);
}
 
int least(int c)
{
int i,nc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i] < min)
{
min=ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
 
if(min!=999)
cost+=kmin;
 
return nc;
}
 void writetoFile(double time)
{
    FILE *f;
    f  = fopen("dyndata.txt","a");
    fprintf(f,"%f \n",time);
    fclose(f);
}
int main()
{
     clock_t start, end;
    double time;
while(n<=100)
{
     start = clock();
     takeInput();
 
printf("\n\nThe Path is:\n");
mincost(0); //passing 0 because starting vertex
 end = clock();
printf("\n\nMinimum cost is %d\n ",cost);
time = (double)(end-start) /CLOCKS_PER_SEC;
writetoFile(time*10000);
        printf("Execution time : %lf", time);
n++;
    
}
return 0;
}
