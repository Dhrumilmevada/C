
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	int c;
	long size;
	int index=0;

	FILE *fp,*fp1;

	fp = fopen("demo.h264","rb");
	fp1 = fopen("write.txt","wb");

	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);

	int buffer[size];

	while((c=getc(fp)) != EOF)
		{
			//printf("%c",c);			
			buffer[index++] = c;
			fputc(c,fp1);
		}
	for(int i=0;i<size;i++)	
		printf("\n%d",buffer[i]);
	
	/*fseek(fp,0,SEEK_END);
	printf("\n%ld\n",ftell(fp));*/

	fclose(fp);
	fclose(fp1);
	/*char *args = "ffplay write.h264";	
	system(args);*/

	fp = fopen("write.txt","rb");
	fp1 = fopen("write.h264","wb");
	
	memset(&buffer,0,sizeof(buffer));
	
	while((c=getc(fp)) != EOF)
		{
			//printf("%c",c);			
			buffer[index++] = c;
			fputc(c,fp1);
		}
	for(int i=0;i<size;i++)	
		printf("\nBuffer:-%d",buffer[i]);

	fclose(fp);
	fclose(fp1);

	char *args = "ffplay write.h264";	
	system(args);
	
return 0;
}
