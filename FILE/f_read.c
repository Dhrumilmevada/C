#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	int buffer[1561666];
	int index=0;
	FILE *fp,*fp1;
	fp = fopen("demo.h264","rb");
	fp1 = fopen("write.h264","wb");

	while((c=getc(fp)) != EOF)
		{
			//printf("%c",c);			
			buffer[index++] = c;
			fputc(c,fp1);
		}
	for(int i=0;i<1561666;i++)	
		printf("\n%d",buffer[i]);
	
	fseek(fp,0,SEEK_END);
	printf("\n%ld\n",ftell(fp));

	fclose(fp);
	fclose(fp1);
	char *args = "ffplay write.h264";	
	system(args);
return 0;
}
