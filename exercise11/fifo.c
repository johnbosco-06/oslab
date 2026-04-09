#include<stdio.h>
#define F 3
int main(){
int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2};
int n=13,frames[F],faults=0,pos=0;
for(int i=0;i<F;i++) frames[i]=-1;
for(int i=0;i<n;i++){
int found=0;
for(int j=0;j<F;j++) if(frames[j]==pages[i]){found=1;break;}
if(!found){frames[pos]=pages[i];pos=(pos+1)%F;faults++;}
}
printf("FIFO Page Faults: %d\n",faults);
return 0;
}
