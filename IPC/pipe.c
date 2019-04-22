#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>


int main()
{
	int fd1[2];
	int fd2[2];
	
	pid_t p;
	
	char start[] = "forgeeks.org";
	char input[100]; 

	if(pipe(fd1)==-1)
	{
		fprintf(stderr,"pipe1 Failed");
		return 1;
	}
	if(pipe(fd2)==-1)
	{
		fprintf(stderr,"pipe2 Failed");
		return 1;
	}

	printf("Enter string:");
	scanf("%s",input);

	p = fork();

	if(p<0)
	{
		fprintf(stderr,"fork failed");
		return 1;
	}
	else if(p > 0)
	{
		char final[100];

		close(fd1[0]);

		write(fd1[1],input,strlen(input)+1);

		close(fd1[1]);

		wait(NULL);

		close(fd2[1]);
		read(fd2[0],final,100);
		close(fd2[0]);

		printf("Final String:-%s\n",final);
		
	}
	else
	{
		char second[100];

		close(fd1[1]);

		read(fd1[0],second,100);

		close(fd1[0]);

		int l = strlen(second);
		int i;
	
		for(i=0;i<strlen(start);i++)
		{
			second[l++] = start[i];
		}
		second[l] = '\0';

		close(fd2[0]);

		write(fd2[1],second,strlen(second)+1);

		close(fd2[1]);
		
	}
return 0;
}
