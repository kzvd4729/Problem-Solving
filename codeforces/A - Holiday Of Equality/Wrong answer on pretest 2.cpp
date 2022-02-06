/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2017 21:12                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++11                               
*  run_time: 0 ms                                            memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/758/problem/A
****************************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int arr[100000],n,sum,avg,largest,diff,ans,i;
    while(scanf("%ld",&n)==1)
    {
        sum=0;
        largest=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
            if(arr[i]>largest)largest=arr[i];
            sum=sum+arr[i];
        }
        avg=sum/n;
        diff=largest-avg;
        ans=diff*n;
        printf("%ld\n",ans);
     }
     return 0;
}