#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 5000
int main(){
	
	int server_soc=0;
	struct sockaddr_in address,tmp;
	char buffer[1024] ;
	socklen_t rec_addr_len = sizeof(tmp);
	char *sendstring = "Server communicating using UDP";
	int n=0; 

	memset(&address,0,sizeof(address));

	if((server_soc=socket(AF_INET,SOCK_DGRAM,0))==0)
	{
		perror("socket creation failed.");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	if(bind(server_soc,(struct sockaddr *)&address,sizeof(address)) < 0)
	{
		perror("Socket binding fail");
		exit(EXIT_FAILURE);
	}

	n = recvfrom(server_soc,buffer,strlen(buffer)+1,0,(struct sockaddr *)&tmp,&rec_addr_len);
	//buffer[n] = '\0';
	printf("Hello, client %d",n);	
	printf("\nClient : ");
	puts(buffer);
	sendto(server_soc,sendstring,strlen(sendstring)+1,0,(struct sockaddr *)&tmp,rec_addr_len);

return 0;
}
