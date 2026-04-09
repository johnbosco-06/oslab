#include<stdio.h>
#define F 3
int main(){
int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2};
int n=13,frames[F],faults=0;
for(int i=0;i<F;i++) frames[i]=-1;
for(int i=0;i<n;i++){
int found=0;
for(int j=0;j<F;j++) if(frames[j]==pages[i]){found=1;break;}
if(!found){
int replace=0,farthest=-1;
for(int j=0;j<F;j++){
int k;
for(k=i+1;k<n;k++) if(frames[j]==pages[k]) break;
if(k>farthest){farthest=k;replace=j;}
}
frames[replace]=pages[i];faults++;
}
}
printf("Optimal Page Faults: %d\n",faults);
return 0;
}
