/****************************************************************************************
*  @author: kzvd4729                                         created: 06-09-2017 19:45:33                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 2.91 sec                                        memory_used: 69.1M                                
*  problem: https://www.codechef.com/SEPT17/problems/FILLMTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 1000005
using namespace std;
vector<pair<long,long> >adj[N];
long vis[N],hei[N],f,t,n,q,u,v,w;
void mem(void)
{
    for(long i=0;i<=1000000;i++)
    {
        hei[i]=0;
        vis[i]=0;
        adj[i].clear();
    }
}
void dfs(long root,long h)
{
    hei[root]=h;
    vis[root]=1;
    for(long i=0;i<adj[root].size();i++)
    {
        long x=adj[root][i].first;
        long c=adj[root][i].second;
        if(vis[x]==1)
        {
            if(abs(hei[root]-hei[x])%2!=c)f=1;
        }
        else dfs(x,h+c);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        mem();
        cin>>n>>q;
        while(q--)
        {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        f=0;
        for(long i=0;i<=1000000;i++)
        {
            if(adj[i].size()==0||vis[i]==1)continue;
            dfs(i,0);
        }
        if(f==1)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}