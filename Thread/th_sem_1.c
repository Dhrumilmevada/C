#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int current_line = 1;

pthread_cond_t  cond ;
pthread_mutex_t lock ;
sem_t mutex; 

void *print_odd(void *arg)
{
	int *line = (int *)arg;
	int i=0;

	sem_wait(&mutex);
	printf("\n");	
	for(i=0;i<(*line);i++)
	{	
		
		//if(current_line % 2 == 1)	
		{
			printf("\n%d -%d-line_odd",i,current_line);	
			printf(" * \n");
			current_line += 1;
		}
		/*else{
			printf("\nline odd else");
			sem_wait(&mutex);
		}*/
		
	}		
	sem_post(&mutex);	
	return NULL;
}

void *print_even(void *arg)
{
	int *line = (int *)arg;
	int i=0;
	
	sem_wait(&mutex);
	for(i=0;i<(*line);i++)
	{
		//if(current_line % 2 == 0)	
		{
			printf("\n%d -%d-line_even",i,current_line);	
			printf("* *\n");
			current_line += 1;
		}
		/*else{
			printf("line even else");
			sem_wait(&mutex);
		}*/
		
	}		
	
	sem_post(&mutex);
	printf("\n thread 2 completed.\n");
	return NULL;
}

int main()
{
	int line=0,line_odd=0,line_even=0;
	printf("Enter number of line you want to print:-");
	scanf("%d",&line);

	line_odd= line - (line/2);
	line_even = line/2;
	
//	printf("%d %d", line_odd,line_even);

	pthread_t tid[2];
	
	sem_init(&mutex,0,1);

	pthread_create(&tid[0],NULL,print_odd, &line_odd);
	pthread_create(&tid[1],NULL,print_even, &line_even);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	sem_destroy(&mutex);
return 0;
}
