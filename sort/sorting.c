#include<stdio.h>
void swap(int* n1,int* n2)
{
	int temp=0;
	temp = (*n1);
	(*n1) = (*n2);
	(*n2) = temp;
}
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

int partition(int arr[] ,int low,int high)
{
	int pivot = 0;
	pivot =  arr[low];
	//printf("\n PAR :- %d \t %d",low,high);
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
	//printf("\n %d %d %d",pivot,arr[j],j);
	swap(&arr[low],&arr[j]);
	//printf("\n %d %d",pivot,arr[j]);

return j;
}
//void quickSort(int [],int ,int);
void quickSort(int arr[],int low,int high)
{
	//printf("\n QUI :- %d \t %d",low,high);
	if(low<high)
	{
		int pos = partition(arr,low,high);
		quickSort(arr,low,pos -1);
		quickSort(arr,pos+1,high);
		//printf("\n pos:- %d",pos);
	}

}
void merge(int arr[],int low,int mid,int high)
{

    int l=0,r=0,i=0;
    int res[7]={0};

    l = low;
    r= mid+1;
    i=low;

    while(l<=mid && r<=high)
    {
        if(arr[l] <= arr[r])
            res[i++]= arr[l++];
        else
            res[i++] = arr[r++];
    }

    while(l<=mid)
        res[i++]= arr[l++];

    while(r<=high)
        res[i++]= arr[r++];

    for(i=low;i<=high;i++)
    {
        arr[i]=res[i];
    }

}
void mergeSort(int arr[],int low,int high)
{
    int mid=0;
    if(low<high)
    {
        mid= (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }

}
void printArray(int arr[], int size)
{
    int i;
	printf("\n");
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int array[] = {1,-3,0,8,-1,-4,-11};
	int n = sizeof(array)/sizeof(int);
	printArray(array,n);
	mergeSort(array,0,n-1);

	printArray(array,n);
	return 0;
}
