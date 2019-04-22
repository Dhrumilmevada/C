#include<stdio.h>

void miniMaxSum(int arr_count, int* arr) {

    int i,j,k=0;
    long int sum[arr_count] ;
    
    for(i=0;i<arr_count;i++)
    {
        sum[i]=0;
    }
    
    for(i=0;i<arr_count;i++){
        for(j=0;j<arr_count;j++)
        {
        if(j==k)
        {
		
            continue;
        }
        sum[i]= sum[i] + (*(arr+j));
        }
	k++;
    }
        
    long int min=sum[0], max=sum[0];
    printf("%ld_",sum[0]);
    for (i=1;i<arr_count;i++)
    {
        printf("%ld_",sum[i]);
        if(sum[i]>max)
            max = sum[i];
        else if(sum[i]<min)
            min = sum[i];
    }
    printf("\n%ld %ld",min,max);
}

int main(){
	int arr_count,i;

	printf("Emter size of array:");
	scanf("%d",&arr_count);

	int arr[arr_count];
	printf("Enter %d number:",arr_count);
	for(i=0;i<arr_count;i++)
	{
		scanf("%d",&arr[i]);
	}	

	miniMaxSum(arr_count,arr);

}
