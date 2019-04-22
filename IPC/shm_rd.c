#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){
	
	key_t key= ftok("shm_file",87);

	int shm_id = shmget(key,1024,IPC_CREAT | 0666);
		
	char *s = (char *)shmat(shm_id,NULL,0);
	printf("\nData read:-%s\n",s);
		
	shmdt(s);
	shmctl(shm_id,IPC_RMID,NULL);
return 0;
}
