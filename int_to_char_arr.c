#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i_array[5] = { 65, 66, 67, 6823, 555 };
    char* c_array[5];

	int i;
	
	/*for(i=0; i<10 ; i++){
		sprintf(&c_tmp[i],"%c",tmp[i]);
	}*/

	for (i; i < 5; i++)
    {   
        //c_array[i] = atoi(i_array[i]);    /* Windows */

        /* Linux */
        // allocate a big enough char to store an int (which is 4bytes, depending on your platform)
        char c[sizeof(i_array[i])];    

        // copy int to char
        snprintf(c, sizeof(i_array[i]), "%d", i_array[i]); //copy those 4bytes

        // allocate enough space on char* array to store this result
        c_array[i] = malloc(sizeof(c)); 
        strcpy(c_array[i], c); // copy to the array of results

        printf("c[%d] = %s\n", i, c_array[i]); //print it
    }   

	/*for(i=0; i<10 ; i++){
		printf("%c",tmp[i]);
	}*/
	return 0;
}
