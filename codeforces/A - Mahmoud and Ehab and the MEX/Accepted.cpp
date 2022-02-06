/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2017 21:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/862/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,ans,arr[102],vis[102],cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>x;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i]==x)ans++;
        if(arr[i]<x&&vis[arr[i]]==0)
        {
            cnt++;
            vis[arr[i]]=1;
        }
    }
    cout<<x-cnt+ans<<endl;
    return 0;
}