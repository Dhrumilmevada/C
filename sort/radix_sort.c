#include<stdio.h>


void print(int arr[],int n)
{
    int i=0;

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

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

void countSort(int arr[],int n,int digit)
{
    int output[n];
    int count_num[10]={0};
    int i=0;
	    
	for(i=0;i<n;i++)
    {
        count_num[ (arr[i]/digit)%10 ]++;
    }
	 print(count_num,10);
    for(i=0;i<10;i++)
    {
        count_num[i] = count_num[i] + count_num[i-1];
    }
    print(count_num,10);
    /*for(i=n-1;i>=0;i--)
    {
        output[count_num[(arr[i]/digit)%10]-1] = arr[i];
        count_num[(arr[i]/digit)%10]--;
    }

    for(i=0;i<n;i++)
        arr[i] = output[i];
*/
}
void radixSort(int arr[],int n)
{
    int max = findMax(arr,n);
    int digit =0;

    for(digit=1; max/digit >0 ; digit*=10)
        countSort(arr,n,digit);
	//continue;
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    radixSort(arr,n);
   // print(arr,n);
	//printf("%d",findMax(arr,n));
 return 0;
}









// C++ implementation of Radix Sort
/*#include<iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}*/
