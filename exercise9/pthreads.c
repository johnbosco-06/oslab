#include<stdio.h>
#include<pthread.h>
void*task(void*arg){
printf("Thread %d running\n",(int)arg);
return NULL;
}
int main(){
pthread_t t[4];
int i;
for(i=0;i<4;i++) pthread_create(&t[i],NULL,task,(void*)i);
for(i=0;i<4;i++) pthread_join(t[i],NULL);
printf("All threads done\n");
return 0;
}
