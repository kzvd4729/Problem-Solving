/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-14 21:53:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10959
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[1002];
queue<long>q;
long dis[1002],t,n,k,u,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(long tc=1;tc<=t;tc++)
    {
        if(tc>1)cout<<endl;
        memset(dis,-1,sizeof(dis));
        for(long i=0;i<=1000;i++)adj[i].clear();
        while(q.size())q.pop();

        cin>>n>>k;
        while(k--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        q.push(0);
        dis[0]=0;

        while(q.size())
        {
            long x=q.front();
            q.pop();
            for(long i=0;i<adj[x].size();i++)
            {
                long z=adj[x][i];
                if(dis[z]>=0)continue;
                dis[z]=dis[x]+1;
                q.push(z);
            }
        }
        for(long i=1;i<n;i++)
        {
            cout<<dis[i]<<endl;
        }
    }
    return 0;
}