#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sched.h>


void* th_demo(void *arg)
{
	printf("\nHello from thread");
	sleep(5);
}
int main()
{

	pthread_t tid;
	pthread_attr_t tattr;
	sched_param param;	
	int rc;

	printf("\nStarted main Thread.");
	rc = pthread_attr_init(&tattr);

	rc = printf(pthread_attr_getschedparam(&tattr,&param));	
	(param.sched_priority)++;
	rc = pthread_attr_setschedparam(&attr,&param);
	rc = pthread_create(&tid,&tattr,th_demo,NULL);
	pthread_join(tid,NULL);
	printf("\nEnding main thread\n");
return 0;
}
