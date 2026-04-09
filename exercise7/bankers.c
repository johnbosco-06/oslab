#include<stdio.h>
#define P 5
#define R 3
int main(){
int alloc[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[R]={3,3,2};
int need[P][R],finish[P]={0},safe[P];
int i,j,k=0;
for(i=0;i<P;i++)
for(j=0;j<R;j++)
need[i][j]=max[i][j]-alloc[i][j];
while(k<P){
int found=0;
for(i=0;i<P;i++){
if(!finish[i]){
int ok=1;
for(j=0;j<R;j++) if(need[i][j]>avail[j]){ok=0;break;}
if(ok){
for(j=0;j<R;j++) avail[j]+=alloc[i][j];
safe[k++]=i;
finish[i]=1;
found=1;
}
}
}
if(!found){printf("Deadlock!\n");return 0;}
}
printf("Safe sequence: ");
for(i=0;i<P;i++) printf("P%d ",safe[i]);
printf("\n");
return 0;
}
