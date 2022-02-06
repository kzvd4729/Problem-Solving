/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2018 22:11                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 18200 KB                             
*  problem: https://codeforces.com/contest/938/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,cost[200005],node,u,v,w;
vector<pair<long,long> >adj[200005];
struct data
{
    long c,id;
}arr[200005];
bool cmp(data A,data B)
{
    return A.c<B.c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].c;
        cost[i]=arr[i].c;
        arr[i].id=i;
    }
    sort(arr+1,arr+n+1,cmp);
    for(long i=1;i<=n;i++)
    {
        node=arr[i].id;
        for(auto x:adj[node])cost[x.first]=min(cost[x.first],cost[node]+2*x.second);
    }
    for(long i=1;i<=n;i++)cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}