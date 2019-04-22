#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 5000


int main()

{
	int client_soc;
	struct sockaddr_in address;
	int valread;
	char buffer[1024] = {0};
	
	if((client_soc = socket(AF_INET,SOCK_STREAM,0)) == 0)
	{
		perror("\nSocket creation error at client.");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);

	if(inet_pton(AF_INET,"10.115.2.243",&address.sin_addr)<=0)
	{
		perror("\nInvalid address or Address nor suppored.");
		exit(EXIT_FAILURE);
	}

	if (connect(client_soc, (struct sockaddr *)&address, sizeof(address)) < 0) 
    { 
       perror("\nConnect not established");
		exit(EXIT_FAILURE);
    }
	send (client_soc,"\nhello from client\n",strlen("hello from client")+1,0);
	valread = read(client_soc,buffer,1024);
	buffer[valread]= '\0';
	printf("\n%s\n",buffer);
	close(client_soc);
	
 return 0;
}
