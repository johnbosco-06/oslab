#include<stdio.h>
#include<stdlib.h>
int main(){
int req[]={98,183,37,122,14,124,65,67};
int n=8,head=53,total=0,visited[8]={0};
printf("SSTF: %d",head);
for(int i=0;i<n;i++){
int min=99999,idx=-1;
for(int j=0;j<n;j++)
if(!visited[j]&&abs(req[j]-head)<min){min=abs(req[j]-head);idx=j;}
visited[idx]=1;total+=min;head=req[idx];
printf("->%d",head);
}
printf("\nTotal: %d\n",total);
return 0;
}
