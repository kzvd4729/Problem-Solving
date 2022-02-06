/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2018 22:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 701 ms                                          memory_used: 23100 KB                             
*  problem: https://codeforces.com/contest/938/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,cost[200005],node,u,v,w;
vector<pair<long,long> >adj[200005];
vector<long>tmp;
set<pair<long,long> >st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(long i=1; i<=n; i++)
    {
        cin>>cost[i];
        st.insert({cost[i],i});
    }
     while(st.size())
    {
        pair<long,long>p=*st.begin();
        st.erase(p);
        for(auto x:adj[p.second])
        {
            if(st.find({cost[x.first],x.first})!=st.end())
            {
                st.erase({cost[x.first],x.first});
                cost[x.first]=min(cost[x.first],cost[p.second]+2*x.second);
                st.insert({cost[x.first],x.first});
            }
        }
//        for(auto x:adj[p.second])
//        {
//            cost[x.first]=min(cost[x.first],cost[p.second]+2*x.second);
//            st.insert({cost[x.first],x.first});
//        }
    }
    for(long i=1; i<=n; i++)cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}