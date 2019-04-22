#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

#define PORT 5000

int main()
{
	int cli_soc=0;
	struct sockaddr_in ser_addr;
	int size = 0;
	int ret=0;
	int total_byte_rec = 0;
	
	memset(&ser_addr,0,sizeof(ser_addr));

	cli_soc = socket(AF_INET,SOCK_STREAM,0);
	
	printf("Socket Created......................\n");
	if(cli_soc==0){
		perror("\nsocket fail.");
		exit(EXIT_FAILURE);
	}

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);
	if(inet_pton(AF_INET,"10.115.2.243",&ser_addr.sin_addr)<=0)
	{
		perror("\nInvalid address or Address nor suppored.");
		exit(EXIT_FAILURE);
	}
	printf("request to  connect servere......................\n");

	if((ret = connect(cli_soc,(struct sockaddr *)&ser_addr,sizeof(ser_addr)))<0)
	{
		perror("\nConnect not established");
		//exit(EXIT_FAILURE);
	}
	printf("\nConnection established.......................\n");
	
	ret = 0;	
	ret = read(cli_soc,&size,sizeof(size));
	printf("\n%d-----%d\n",size,ret);

	int buffer[size];
	memset(&buffer,0,sizeof(buffer));

	ret = 0;
	while(total_byte_rec < sizeof(buffer))
	{
		ret = read(cli_soc,&buffer[total_byte_rec],sizeof(buffer)-total_byte_rec);
		if(ret == -1)
			break;
		total_byte_rec += ret;
		printf("\n%d-----%d\n",ret,total_byte_rec);
	}
	
	printf("\nExist Socket\n");
	close(cli_soc);

	FILE *fp;
	int bf_cnt = 0;
	fp = fopen("output.h264","wb");
	
	while(bf_cnt < size)
	{
		fputc(buffer[bf_cnt++],fp);
	}

	fclose(fp);
return 0;
}
