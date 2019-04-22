#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t cond;
pthread_mutex_t lock;

typedef struct
{
	int *data;
	int size;
}buf;

void *r_file(void *args)
{
	printf("\nReading thread started....\n");
	buf *buffer = (buf *)args;
	int size = buffer->size;
	int bf_cnt = 0;
	
	FILE *fp;
	fp = fopen("demo.h264","rb");

	int c;
	int key = ftok("demo.h264",81);
	int shmid = shmget(key,sizeof(int),IPC_CREAT|0666);
	int *s;
		
	pthread_mutex_lock(&lock);	
	
	while((c=fgetc(fp))!=EOF)
	{
		pthread_cond_signal(&cond);
		 s = (int *)shmat(shmid,NULL,0);
		 *s = c;
		printf("\n R.....%d-----%d",*s,bf_cnt);
		shmdt(s);
		//bf_cnt++;
		if(bf_cnt++ != size){
			printf("\nIn if of read\n");
			pthread_cond_wait(&cond,&lock);}
	}
	pthread_mutex_unlock(&lock);
	printf("\nCompleted Thread-1\n");
pthread_exit(NULL);
}

void *w_file(void *args)
{
	buf *buffer = (buf *)args;
	int size = buffer->size;
	int bf_cnt = 0;

	int key = ftok("demo.h264",81);
	int shmid = shmget(key,sizeof(int),IPC_CREAT|0666);
	int *s;

	pthread_mutex_lock(&lock);
	while(bf_cnt < size)
	{
		pthread_cond_signal(&cond);
		s = (int *)shmat(shmid,NULL,0);
		(buffer->data[bf_cnt]) = *s;
		printf("\n W.....%d-----%d\n",buffer->data[bf_cnt],bf_cnt);
		shmdt(s);
		//bf_cnt++;
		if(bf_cnt++ != size-1){
			printf("\nIn if of write\n");
			pthread_cond_wait(&cond,&lock);}		
	}
	pthread_mutex_unlock(&lock);
	printf("\nCompleted Thread-2\n");
pthread_exit(NULL);	
}

int main()
{

	FILE *fp = fopen("demo.h264","rb");
	fseek(fp,0,SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	fclose(fp);
	
	printf("%d\n",size);
	sleep(5);

	int dataset[size];
	memset(&dataset,0,sizeof(dataset));
	
	buf buffer;
	buffer.data = &dataset;
	buffer.size = size;

	pthread_t tid[2];

	if(pthread_mutex_init(&lock,NULL)==0)
	{
		pthread_create(&tid[0],NULL,r_file,&buffer);
		pthread_create(&tid[1],NULL,w_file,&buffer);
	}
	
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_mutex_destroy(&lock);
	
	printf("\nback to main\n");


	printf("\n%d\n",(int)sizeof(dataset));

	sleep(5);

	fp = fopen("output.h264","wb");
	int buf_cnt=0;
	
	while(buf_cnt < size)
	{
		printf("\n%d-----%d\n",dataset[buf_cnt],buf_cnt);
		fputc(dataset[buf_cnt++],fp);
	}	
	fclose(fp);	

return 0;
}
