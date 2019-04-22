#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 5000

int main(){
	
	int client_soc=0;
	struct sockaddr_in address,ser_addr,tmp;
	char *sendstring = "Client communicating using UDP";
	char buffer[1024];
	socklen_t rec_addr_len = sizeof(tmp);
	int n=0;
	

	memset(&address,0,sizeof(address));
	memset(&ser_addr,0,sizeof(ser_addr));
	memset(&tmp,0,sizeof(tmp));

	if((client_soc=socket(AF_INET,SOCK_DGRAM,0))==0)
	{
		perror("socket creation failed.");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = inet_addr("10.115.2.243");
	ser_addr.sin_port = htons(PORT);

	/*if(bind(client_soc,(struct sockaddr *)&address,sizeof(address)) < 0)
	{
		perror("Socket binding fail");
		exit(EXIT_FAILURE);
	}*/

	sendto(client_soc,sendstring,strlen(sendstring)+1,0,(struct sockaddr *)&ser_addr,rec_addr_len);

	n=recvfrom(client_soc,buffer,strlen(buffer)+1,0,(struct sockaddr *)&tmp,&rec_addr_len);
	//buffer[n] = '\0';
	printf("Hello Server %d %d",n,(int)strlen(sendstring)+1);
	printf("\nServer : ");
	puts(buffer);

return 0;
}
