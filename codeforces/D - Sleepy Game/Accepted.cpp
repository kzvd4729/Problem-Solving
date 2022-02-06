/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2018 18:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 25600 KB                             
*  problem: https://codeforces.com/contest/937/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,x,s,vis[200005][3],print[200005],v,on[200005];
vector<long>adj[200005];
void dfs(long node,long ck,long id)
{
    if(!adj[node].size()&&ck)
    {
        cout<<"Win"<<endl;
        print[id]=node;
        for(long i=1;i<=id;i++)cout<<print[i]<<" ";
        cout<<endl;
        exit(0);
    }
    if(vis[node][ck])return ;
    vis[node][ck]=1;
    print[id]=node;
    for(auto x:adj[node])dfs(x,ck^1,id+1);
}
void cycle(long node)
{
    if(on[node])
    {
        cout<<"Draw"<<endl;
        exit(0);
    }
    on[node]=1;
    for(auto x:adj[node])cycle(x);
    on[node]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        while(x--)
        {
            cin>>v;
            adj[i].push_back(v);
        }
    }
    cin>>s;
    dfs(s,0,1);
    cycle(s);
    cout<<"Lose"<<endl;
    return 0;
}