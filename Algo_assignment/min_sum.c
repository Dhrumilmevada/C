/******************************************************************************
 *
 * @file    min_sum.c
 * @author  Dhrumil Mevada
 * @brief   File sort a data using different sort algorithm and calcutate time.
 * @date	SEP 1,2018 ,Created
 *          
 *****************************************************************************/

/***************
 * Include Files
 ***************/
#include"sort.h"
#include<math.h>

/** Function    main
 * @date        SEP/1/2018
 * @brief       Main function of the program.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 */
int main(){

    int n=0,i=0,j=0;

    printf("\nEnter Size of data :-");
    scanf("%d",&n);			//To get size of data

    int arr[n];				//To store data
    fillArrayDefault(arr,n);
    fillArray(arr,n);
    quickSort(arr,0,n-1);		//to sort entered data	
    printArray(arr,n);

    int first=0,second=0,sum=10000;	//to point to first and last number which we are going to sum	
    i=0;
	if(n>0){
		if(arr[i] >= 0)
		{
		    first = arr[i];			//if first element is 0 or more than zero
		    second = arr[i+1];
		    sum= first + second;
		}
	   else{
		    for(i=0;i<n-1 && arr[i]<=0 ;i++)
		    {
		        first = arr[i];
		        for(j=i+1;j<n;j++)				// If data has nagative number
		        {
		            if(abs(sum) > abs(0-(first + arr[j])))
		            {
		                second = arr[j];
		                sum = first + second;
		            }
		        }
		    }
		}
	printf("\n\n\tLowest sum is sum of %d and %d : %d\n\n",first,second,sum);    //To print numbre whose sum is close to zero
	}

    
    return 0;
}
