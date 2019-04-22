#include<iostream>

using namespace std;

//This function will check every contiguous subarray and return the sum of maximum subarray
int maxSubarraySum(int a[], int n)
{
    int overall_sum=0;  //overall maximum subarray sum
    int new_sum;
 
    for(int i=0;i<n;i++)
    {
        //find the maximum subarray sum of the subarray starting from a[i]
        new_sum=0;
        for(int j=i;j<n;j++)
        {
            new_sum+=a[j];
            if(new_sum>overall_sum)
            {
              overall_sum=new_sum;
            }
        }
    }
    return overall_sum;
}
int main()
{
    int i,n;
    cout<<"Enter the number of elements in the array  ";
    cin>>n;
    int a[n];
    //read the vector
    cout<<"enter the elements in the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //now,make a call to kadane function to calculate maximum subarray sum
    cout<<endl<<"The maximum subarray sum for the given array is "<<maxSubarraySum(a,n)<<"\n"; 
    return 0;
}
