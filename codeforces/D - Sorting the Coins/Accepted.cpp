/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 6600 KB                              
*  problem: https://codeforces.com/contest/876/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[300005],vis[300005],nn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)cin>>arr[i];
    cout<<1<<" ";
    nn=n;
    for(long i=1;i<=n;i++)
    {
        vis[arr[i]]=1;
        while(vis[nn])nn--;
        cout<<i-(n-nn)+1<<" ";
    }
     return 0;
 }