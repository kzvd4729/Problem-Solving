/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 22:32                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C                                   
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/953/problem/B
****************************************************************************************/
#include<stdio.h>
int n,arr[100005],i,mx,gcd,x;
int call_gcd(int a, int b)
{
    while (b != 0)
    {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
     return a;
}
/* C program for Merge Sort */
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
     /* create temp arrays */
    int L[n1], R[n2];
     /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
     /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
     /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
     /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 /* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
         // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
         merge(arr, l, m, r);
    }
}
 int main()
{
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&arr[i]);
  mergeSort(arr,1,n);
//  for(i=1;i<=n;i++)printf("%d ",arr[i]);
//  printf("\n");
  gcd=0;
  for(i=1;i<n;i++)
  {
    x=arr[i+1]-arr[i];
    if(x>mx)mx=x;
    //printf("%d",x);
    //printf("%d",gcd);
    gcd=call_gcd(gcd,x);
  }
  printf("%d\n",(mx/gcd)-1);
  return 0;
}