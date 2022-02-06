/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2017 17:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/890/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[200005],n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        arr[x]=i;
    }
    long mx=0,ans;
    for(long i=0;i<=200000;i++)
    {
        if(arr[i]==0)continue;
        if(n-arr[i]+1>mx)
        {
            mx=n-arr[i]+1;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}