#include<stdio.h>
int main(){
int blocks[]={100,500,200,300,600};
int procs[]={212,417,112,426};
int bn=5,pn=4,alloc[4];
for(int i=0;i<pn;i++) alloc[i]=-1;
for(int i=0;i<pn;i++)
for(int j=0;j<bn;j++)
if(blocks[j]>=procs[i]){alloc[i]=j;blocks[j]-=procs[i];break;}
printf("Process\tSize\tBlock\n");
for(int i=0;i<pn;i++)
printf("%d\t%d\t%s%d\n",i+1,procs[i],alloc[i]==-1?"NA":"",(alloc[i]==-1)?0:alloc[i]+1);
return 0;
}
