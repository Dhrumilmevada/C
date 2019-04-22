/******************************************************************************
 *
 * @file    sorting.c
 * @author  Dhrumil Mevada
 * @brief   File sort a data using different sort algorithm and calcutate time.
 * @date	AUG 31,2018 ,Created
 *          
 *****************************************************************************/

/***************
 * Include Files
 ***************/
#include"sort.h"
#include<time.h>
#include<stdlib.h>


/** Function    main
 * @date        AUG/91/2018
 * @brief       Main function of the program.
 * 
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 */
int main()
{

	int n=0;		//!< To store size of data 
	int arr[n];		//!< To store the data
	int ch = 0;		//!< to make choice
	clock_t start,end;	// To store start and end time
	double used_time;	//To calculate time taken by function 
	

	while(1)
	{

		printf("\n\n\t1. Bubble Sort");
		printf("\n\t2. Radix Sort");		
		printf("\n\t3. quick Sort");
		printf("\n\t4.  Exit");

		printf("\n\nEnter your choice :-");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter size of data:-");
				scanf("%d",&n);
			
				fillArrayDefault(arr,n);
				fillArray(arr,n);

				start = clock();
				radixSort(arr,n);
				end = clock();

				printArray(arr,n);

				used_time = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n Time take  to sort is %lf second.",used_time);
				break;
			case 2:
				printf("\nEnter size of data:-");
				scanf("%d",&n);
			
				fillArrayDefault(arr,n);
				fillArray(arr,n);

				start = clock();
				bubbleSort(arr,n);
				end = clock();

				printArray(arr,n);

				used_time = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n Time take  to sort is %lf second.",used_time);
				break;
			case 3:
				printf("\nEnter size of data:-");
				scanf("%d",&n);
			
				fillArrayDefault(arr,n);
				fillArray(arr,n);

				start = clock();
				quickSort(arr,0,n-1);
				end = clock();

				printArray(arr,n);

				used_time = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n Time take  to sort is %lf second.",used_time);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nYou enter wrong choice");
				break;
		}
	}
	return 0;
}
