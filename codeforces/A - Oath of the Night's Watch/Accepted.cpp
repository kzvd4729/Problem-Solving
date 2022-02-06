/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/20/2017 22:15                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 265 ms                                          memory_used: 2800 KB                              
*  problem: https://codeforces.com/contest/768/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long arr[100003];
int main()
{
    long long int n,cnt,i;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]>arr[0]&&arr[i]<arr[n-1])cnt++;
        }
        cout<<cnt<<endl;
     }
      return 0;
}