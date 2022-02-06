/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2017 21:14                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/758/problem/A
****************************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int arr[100000],n,sum,largest,diff,ans,i;
    while(scanf("%ld",&n)==1)
    {
        sum=0;
        largest=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
            if(arr[i]>largest)largest=arr[i];
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            diff=largest-arr[i];
            ans=ans+diff;
        }
        printf("%ld\n",ans);
      }
     return 0;
}