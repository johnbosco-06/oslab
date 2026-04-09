#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
int req[]={98,183,37,122,14,124,65,67};
int n=8,head=53,total=0;
qsort(req,n,sizeof(int),cmp);
int i;
for(i=0;i<n;i++) if(req[i]>=head) break;
printf("SCAN: %d",head);
for(int j=i;j<n;j++){total+=abs(req[j]-head);head=req[j];printf("->%d",head);}
for(int j=i-1;j>=0;j--){total+=abs(req[j]-head);head=req[j];printf("->%d",head);}
printf("\nTotal: %d\n",total);
return 0;
}
