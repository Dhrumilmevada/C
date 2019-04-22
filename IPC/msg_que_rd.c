#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

typedef struct {
	long msg_type;
	char msg[100];
}message;

int main()
{
	
	message msg;

	key_t key;
	
	int msg_id;

	key = ftok("msg_que",75);
	if (key == -1)
	{
		perror("Key fail");
	}
	printf("%d\n",(int )key);
	
	msg_id = msgget(key , IPC_CREAT |/* IPC_EXCL  |*/ 0666);
	if (msg_id == -1){
		perror("msgget fail");
	}
	while(1){
		msgrcv(msg_id,&msg,sizeof(msg),1,0);

		printf("Message recieved :-");
		puts(msg.msg);
	}
	msgctl(msg_id,IPC_RMID,NULL);
return 0;
}
