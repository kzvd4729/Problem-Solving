/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/11/2018 00:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1278 ms                                         memory_used: 162300 KB                            
*  problem: https://codeforces.com/contest/545/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=99999999999999999;
long n,m,u,v,w,nod,dis[3000005],node,id,arr[3000005],vis[3000005],sum,cost;
vector<pair<long,long> >adj[3000005];
map<pair<long,long>,long>mp;
vector<long>ans;
priority_queue<pair<pair<long,long>,pair<long,long> > >pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        if(u>v)swap(u,v);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        mp[{u,v}]=i;
        arr[i]=w;
    }
    for(long i=1;i<=n;i++)dis[i]=inf;
    cin>>nod;
    dis[nod]=0;
    pq.push({{0,0},{0,nod}});
    while(pq.size())
    {
        pair<pair<long,long>,pair<long,long> >p=pq.top();
        pq.pop();
        cost=-p.first.second;
        id=p.second.first;
        nod=p.second.second;
        if(vis[nod])continue;
        vis[nod]=1;
        sum+=cost;
        ans.push_back(id);
        for(auto x:adj[nod])
        {
            long xx=x.first;
            long cc=x.second;
            if(vis[xx])continue;
            if((dis[nod]+cc)<=dis[xx])
            {
                dis[xx]=dis[nod]+cc;
                pq.push({{-dis[xx],-arr[mp[{min(nod,xx),max(nod,xx)}]]},{mp[{min(nod,xx),max(nod,xx)}],xx}});
            }
        }
    }
    cout<<sum<<endl;
    for(long i=1;i<ans.size();i++)cout<<ans[i]<<endl;
    return 0;
}