/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2018 21:40                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/811/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[5003],num[5003],n;
map<long,long>mp;
struct data
{
    long first,last;
} arr[5003];
int main()
{
    cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>num[i];
        if(arr[num[i]].first==0)arr[num[i]].first=i;
        arr[num[i]].last=i;
    }
    for(long k=1; k<=n; k++)
    {
        dp[k]=max(dp[k],dp[k-1]);
        long x=num[k],f=0,xr=0;
        mp.clear();
        for(long i=arr[x].first; i<=arr[x].last; i++)
        {
            if(arr[num[i]].first<arr[x].first||arr[num[i]].last>arr[x].last)
            {
                f=-1;
                break;
            }
            if(mp[num[i]]==0)
            {
                xr=xr^num[i];
                mp[num[i]]=1;
            }
        }
        if(f==-1)xr=0;
        dp[arr[x].last]=max(dp[arr[x].last],dp[arr[x].first-1]+xr);
    }
    cout<<dp[n]<<endl;
    return 0;
}