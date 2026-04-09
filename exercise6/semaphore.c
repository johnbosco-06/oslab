#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s;
int shared=0;
void*thread(void*arg){
sem_wait(&s);
shared++;
printf("Thread %d: shared=%d\n",(int)arg,shared);
sem_post(&s);
return NULL;
}
int main(){
pthread_t t[3];
sem_init(&s,0,1);
for(int i=0;i<3;i++) pthread_create(&t[i],NULL,thread,(void*)i);
for(int i=0;i<3;i++) pthread_join(t[i],NULL);
sem_destroy(&s);
return 0;
}
