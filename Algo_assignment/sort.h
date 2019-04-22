/***************
 * Include Files
 ***************/
#include<stdio.h>


/** Function    fillArrayDefault
 * @date        AUG/31/2018
 * @brief       To fill the array with zero.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void fillArrayDefault(int arr[],int n)
{
    int i=0;

    for(i=0;i<n;i++)
    {
        arr[i]=0;
    }
}

/** Function    fillArray
 * @date        AUG/31/2018
 * @brief       To fill the array with user input.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void fillArray(int arr[],int n)
{
    int i=0;

    for(i=0;i<n;i++)
    {
        printf("\nEnter data[%d]:",i+1);
        scanf("%d",&arr[i]);
    }
}

/** Function    swap
 * @date        AUG/31/2018
 * @brief       To swap two number.
 * @param 		int* : n1: first number to swap.
 * 				int* : n2: second number to swap.
 * @return		void. 	
 */
void swap(int* n1,int* n2)
{
	int temp=0;
	temp = (*n1);
	(*n1) = (*n2);
	(*n2) = temp;
}

/** Function    selectionSort
 * @date        AUG/31/2018
 * @brief       To sort data using selection sort.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void selectionSort(int arr[], int n)
{
	int i=0,j=0,temp=0;

    printf("\n\nUsing Selection Sort....\n");
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[i])
          {
			swap(&arr[i],&arr[j]);		
			}
	}
}


/** Function    bubbleSort
 * @date        AUG/31/2018
 * @brief       To sort data using bubble sort algorithm.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */

void bubbleSort(int arr[],int n)
{
	int i=0,j=0,temp=0;
	printf("\n\nUsing Buuble Sort....\n");
	for(i=0 ; i<n-1 ; i++)
	{
		for(j=0;j< n-1-i;j++)
		{
			if(arr[j+1] < arr[j])
			{
				swap(&arr[j+1],&arr[j]);
			}
		}
	}
}


/** Function    insertionSort
 * @date        AUG/31/2018
 * @brief       To sort data using insertion sort algoritm.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void insertionSort(int arr[],int n)
{
	int i=0,j=0,temp=0;

	printf("\n\nUsing Insertion sort...\n");
	for(i=1;i<n;i++)
	{

		temp = arr[i];
		j = i-1;
		while(j>= 0 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
	arr[j+1] = temp;
	}
}


/** Function    findMax
 * @date        AUG/31/2018
 * @brief       To find maximux number from data.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
int findMax(int arr[],int n)
{
    int max = arr[0];
    int i=0;
    for(i=1;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}


/** Function    countSort
 * @date        AUG/31/2018
 * @brief       To sort data using perticular digit in number.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */

void countSort(int arr[],int n,int digit)
{
    int output[n];
    int count_num[10]={0};
    int i=0;

	for(i=0;i<n;i++)
    {
        count_num[ (arr[i]/digit)%10 ]++;
    }

    for(i=1;i<10;i++)
    {
        count_num[i] = count_num[i] + count_num[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[count_num[(arr[i]/digit)%10]-1] = arr[i];
        count_num[(arr[i]/digit)%10]--;
    }

    for(i=0;i<n;i++)
        arr[i] = output[i];

}

/** Function    redSort
 * @date        AUG/31/2018
 * @brief       To sort data using radix sort algorithm.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */

void radSort(int arr[],int n)
{
    int max = findMax(arr,n);
    int digit =0,i=0;

    for(digit=1; max/digit >0 ; digit*=10)
        countSort(arr,n,digit);
}

/** Function    radixSort
 * @date        AUG/31/2018
 * @brief       To sort nagative and positive number sepereatally using radix sort.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void radixSort(int arr[],int n)
{
    int neg_num[n],neg_cnt=0;
    int pos_num[n],pos_cnt=0;
    fillArrayDefault(neg_num,neg_cnt);
    fillArrayDefault(pos_num,pos_cnt);
    int i=0,j=0;


    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            neg_num[neg_cnt++] =( -1 * arr[i]);
        }
        else
        {
            pos_num[pos_cnt++]= arr[i];
        }
    }
    radSort(neg_num,neg_cnt);
    radSort(pos_num,pos_cnt);

    for(i=0;i<neg_cnt;i++)
    {
        arr[i] = -1 * neg_num[neg_cnt-1-i];
    }

    for(i=neg_cnt,j=0;i<n;i++)
    {
        arr[i] = pos_num[j++];
    }

}

/** Function    partition
 * @date        AUG/31/2018
 * @brief       To partition array and return postion where it is partitioned.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		int : postion where it is partitioned.
 */
int partition(int arr[] ,int low,int high)
{
	int pivot = 0;
	pivot =  arr[low];
	int i = low ;
	int j = high+1;
	do
	{
		do
		{
			i++;
        }
        while(arr[i]<=pivot && i<high);

		do
		{
			j--;
        }
        while(j>0 && arr[j]>pivot);

		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
		else
			break;
	}
	while(i<j);
	swap(&arr[low],&arr[j]);
return j;
}

/** 
 * @Function    quickSort
 * @date        AUG/31/2018
 * @brief       To sort the data using quick sort algorithm.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */
void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pos = partition(arr,low,high);
		quickSort(arr,low,pos -1);
		quickSort(arr,pos+1,high);
	}

}
/** 
 * @Function    printArray
 * @date        AUG/31/2018
 * @brief       To print array.
 * @param 		int: arr[]: stored data
 * 				int: n: size of data.
 * @return		void 	
 */

void printArray(int arr[], int size)
{
    int i;
	printf("\n");
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
