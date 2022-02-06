/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2017 21:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/617/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,arr[111],dp[111],last,i,s;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    for(i=1; i<=n; i++)
    {
        if(arr[i]==1)
        {
            last=i;
            dp[last]=1;
            break;
        }
    }
    if(s==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(s==1)
    {
        cout<<1<<endl;
        return 0;
    }
     for(i=last+1; i<=n; i++)
    {
        if(arr[i]==1)
        {
            dp[i]=(i-last)*dp[last];
            last=i;
        }
    }
    cout<<dp[last]<<endl;
    return 0;
}