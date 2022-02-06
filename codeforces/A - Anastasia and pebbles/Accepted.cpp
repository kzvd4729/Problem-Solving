/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2017 22:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/789/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,arr[100005],i,ans;
    double x,sum;
    while(cin>>n>>k)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            x=ceil((double)arr[i]/(double)k);
            sum=sum+x;
        }
        ans=ceil(sum/2);
        cout<<ans<<endl;
      }
     return 0;
}