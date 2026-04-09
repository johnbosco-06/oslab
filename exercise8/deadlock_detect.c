#include<stdio.h>
#define P 4
#define R 3
int main(){
int alloc[P][R]={{0,1,0},{2,0,0},{3,0,3},{2,1,1}};
int req[P][R]={{0,0,0},{2,0,2},{0,0,0},{1,0,0}};
int avail[R]={0,0,0};
int finish[P]={0};
int i,j,k;
for(i=0;i<P;i++)
for(j=0;j<R;j++)
avail[j]+=alloc[i][j];
avail[0]=0;avail[1]=0;avail[2]=0;
int work[R]={0,0,0};
while(1){
int found=0;
for(i=0;i<P;i++){
if(!finish[i]){
int ok=1;
for(j=0;j<R;j++) if(req[i][j]>work[j]){ok=0;break;}
if(ok){
for(j=0;j<R;j++) work[j]+=alloc[i][j];
finish[i]=1;found=1;
}
}
}
if(!found) break;
}
printf("Deadlocked processes: ");
int d=0;
for(i=0;i<P;i++) if(!finish[i]){printf("P%d ",i);d=1;}
if(!d) printf("None");
printf("\n");
return 0;
}
