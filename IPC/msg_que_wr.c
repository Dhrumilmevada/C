#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

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
	
	msg_id = msgget(key ,IPC_CREAT | /*IPC_EXCL |*/ 0666);
	if (msg_id == -1){
		perror("msgget fail");
	}
	while(1){
		msg.msg_type = 1;
	
		printf("Write Data: ");
		gets(msg.msg);

		msgsnd(msg_id,&msg,sizeof(msg),0);
		printf("Send data is :- %s\n",msg.msg);
	}
	return 0;	
}
