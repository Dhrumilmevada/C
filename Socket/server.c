#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


#define PORT 5000

int main()
{
	int server_soc=0,new_soc=0;
	struct sockaddr_in address,clint_addr;
	char buffer[1024] = {0};
	int addrlen = sizeof(clint_addr);
	int valread;
	int opt = 1;
	

	if((server_soc = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("\nSocket_failed.");
		exit(EXIT_FAILURE);
	}
	printf("%d",server_soc);

	memset(&address, 0 , sizeof(address));
	memset(&clint_addr, 0 , sizeof(clint_addr));
	memset(&buffer, 0 , sizeof(buffer));

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = /*htonl*/(INADDR_ANY);
	//address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORT);
/*
	if (setsockopt(server_soc, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
	 perror("Set Socket Option error"); 
     exit(EXIT_FAILURE); 
   	}*/

	if(bind(server_soc, (struct sockaddr *)&address,sizeof(address)) < 0)
	{
		perror("\nBind fail.");
		exit(EXIT_FAILURE);
	}

	if(listen(server_soc,5) < 0)
	{
		perror("\nlisten fail");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		if((new_soc	= accept(server_soc, (struct sockaddr *)&clint_addr, (socklen_t *)&addrlen)) < 0)
		{
			perror("\nAccept fail");
			exit(EXIT_FAILURE);
		}
		valread = read(new_soc,buffer,1024);
		printf("\n%s\n",buffer);
		send(new_soc,"\nHello from server\n",strlen("Hello from server")+1 , 0);
	}
return 0;
}
