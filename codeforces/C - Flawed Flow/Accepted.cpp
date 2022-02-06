/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2018 11:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/269/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int ans[N+2],rem[N+2],vis[N+2];
struct edge
{
    int nxt,wgt,dir,id;
};
vector<edge>adj[N+2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w,0,i});
        adj[v].push_back({u,w,1,i});
    }
    set<pair<int,int> >st;
    for(int i=2;i<n;i++)
    {
        int sum=0;
        for(auto x:adj[i])
            sum+=x.wgt;
        rem[i]=sum/2;
        st.insert({sum/2,i});
    }
    for(auto x:adj[1])
    {
        ans[x.id]=x.dir;vis[x.id]=1;
        if(x.nxt==n)continue;
        st.erase({rem[x.nxt],x.nxt});
        rem[x.nxt]-=x.wgt;
        st.insert({rem[x.nxt],x.nxt});
    }
    while(st.size())
    {
        pair<int,int>p=*st.begin();
        st.erase(p);
        for(auto x:adj[p.second])
        {
            if(vis[x.id])continue;
            ans[x.id]=x.dir;vis[x.id]=1;
            if(x.nxt==n)continue;
            st.erase({rem[x.nxt],x.nxt});
            rem[x.nxt]-=x.wgt;
            st.insert({rem[x.nxt],x.nxt});
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}