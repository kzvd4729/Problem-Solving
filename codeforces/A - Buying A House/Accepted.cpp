/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2017 22:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/796/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,arr[109],vis[109],d,dd,i;
    cin>>n>>m>>k;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]>0&&arr[i]<=k)vis[i]=1;
    }
     dd=999999;
     for(i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            d=abs(i-m)*10;
            if(d<dd)dd=d;
        }
    }
    cout<<dd<<endl;
    return 0;
}