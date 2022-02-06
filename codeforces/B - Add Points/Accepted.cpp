/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 11:11                        
*  solution_verdict: Accepted                                language: GNU C11                                 
*  run_time: 62 ms                                           memory_used: 4000 KB                              
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
    k = l;
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
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
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
  gcd=0;
  for(i=1;i<n;i++)
  {
    x=arr[i+1]-arr[i];
    if(x>mx)mx=x;
    gcd=call_gcd(gcd,x);
  }
  int ans=0;
  for(i=1;i<n;i++)
  {
      x=arr[i+1]-arr[i];
      ans=ans+(x/gcd)-1;
  }
  printf("%d\n",ans);
  return 0;
}