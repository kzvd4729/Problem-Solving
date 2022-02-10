/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-25 22:36:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 46                                         memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/URAL-1280
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long fr[1003],n,u,v,m,x;
vector<long>adj[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        fr[v]++;
    }
    long f=0;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        if(fr[x]!=0)f=1;
        for(long i=0;i<adj[x].size();i++)
        {
            long xx=adj[x][i];
            fr[xx]--;
        }
    }
    if(f)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}