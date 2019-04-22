#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){
	
	key_t key= ftok("shm_file",87);

	int shm_id = shmget(key,1024,IPC_CREAT | 0666);
	
	char *s = (char *)shmat(shm_id,NULL,0);
	printf("Write Data :-");	
	fgets(s,sizeof(s),stdin);		
	printf("\nData writen:-%s\n",s);

	shmdt(s);
return 0;
}

