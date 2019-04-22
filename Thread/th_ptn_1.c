#include<stdio.h>
#include<pthread.h>

int current_line = 1;

pthread_cond_t  cond ;
pthread_mutex_t lock ;

void *print_odd(void *arg)
{
	int *line = (int *)arg;
	int i=0;

	pthread_mutex_lock(&lock);
	printf("\n");	
	for(i=0;i<(*line);i++)
	{	
		pthread_cond_signal(&cond);
		if(current_line % 2 == 1)	
		{
			//printf("\n%d -%d-line_odd",i,current_line);	
			printf(" * \n");
			current_line += 1;
			if(i != (*line)-1)		
				pthread_cond_wait(&cond,&lock);
		}
		else{
			//printf("\nline odd else");
			pthread_cond_signal(&cond);
		}
		
	}		
	pthread_mutex_unlock(&lock); 	
	return NULL;
}

void *print_even(void *arg)
{
	int *line = (int *)arg;
	int i=0;
	
	
	pthread_mutex_lock(&lock);
	for(i=0;i<(*line);i++)
	{
		pthread_cond_signal(&cond);
		if(current_line % 2 == 0)	
		{
			//printf("\n%d -%d-line_even",i,current_line);	
			printf("* *\n");
			current_line += 1;
			if(i != (*line)-1)
				pthread_cond_wait(&cond,&lock);
		}
		else{
			//printf("line even else");
			pthread_cond_signal(&cond);
		}
		
	}		
	
	pthread_mutex_unlock(&lock);
	//printf("\n thread 2 completed.");
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

	if(pthread_mutex_init(&lock,NULL)==0)
	{
		pthread_create(&tid[0],NULL,print_odd, &line_odd);
		pthread_create(&tid[1],NULL,print_even, &line_even);
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_mutex_destroy(&lock);
return 0;
}
