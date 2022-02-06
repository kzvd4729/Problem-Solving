/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2017 16:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 483 ms                                          memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/368/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int i,n,m,arr[100005],brr[100005],ans[100004],vis[100005];
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)cin>>arr[i];
    for(i=1; i<=m; i++)cin>>brr[i];
    for(i=n; i>=1; i--)
    {
         if(vis[arr[i]]==0)
        {
            ans[i]=ans[i+1]+1;
            vis[arr[i]]=1;
        }
        else ans[i]=ans[i+1];
     }
    for(i=1; i<=m; i++)
    {
        cout<<ans[brr[i]]<<endl;
    }
     return 0;
}