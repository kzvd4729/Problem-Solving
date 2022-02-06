/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2018 16:16                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 236600 KB                            
*  problem: https://codeforces.com/contest/283/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2,R=1e5;
const long mod=1e9+7;
int cn[N+2],cnt;
long mm[N+2][2],sum;
int n,q,t;
int in[N+2],lin[N+2],id;
bool vis[N+2];
int parent[N+2];
vector<int>adj[N+2],rt;
void dfs0(int node)
{
    sum+=cn[node];
    for(auto x:adj[node])
    {
        dfs0(x);
    }
}
void dfs1(int node,int lv)
{
    sum+=(cn[node]*1LL)*lv;
    if(sum>t)sum=t+10;
    for(auto x:adj[node])
    {
        dfs1(x,lv+1);
    }
}
void dfs2(int node,int par)
{
    lin[++id]=node;parent[node]=par;
    for(auto x:adj[node])
    {
        dfs2(x,par);
    }
}
void dfs3(int node)
{
    cnt++;
    if(cnt>400)cout<<0<<endl,exit(0);
    for(auto x:adj[node])
    {
        dfs3(x);
    }
}
int mem[2][302][100005];
int dfs(int st,int vl,int f)
{
    if(vl<0) return 0;
    if(st>n)
    {
        if(vl==0)return 1;
        else return 0;
    }
    int &res=mem[f][st][vl];
    if(res) return res;
    res=0;int g=0;
    if(f==0)
    {
        res=(res+dfs(st,vl-mm[lin[st]][1],1))%mod;
        if(parent[lin[st]]==parent[lin[st+1]])
        {
            res+=dfs(st+1,vl-mm[lin[st+1]][1],1);
        }
        else res+=dfs(st+1,vl,0);
    }
    else
    {
        res+=dfs(st,vl-mm[lin[st]][0],1);
        if(parent[lin[st]]==parent[lin[st+1]])
        {
            res+=dfs(st+1,vl,1);
        }
        else res+=dfs(st+1,vl,0);
    }
    return res%=mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q>>t;
    for(int i=1;i<=n;i++)cin>>cn[i];
    for(int i=1;i<=q;i++)
    {
        int u,v;cin>>u>>v;
        in[u]++;
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        dfs3(i);
    }
    for(int i=1;i<=n;i++)
        if(in[i]==0)rt.push_back(i);
    for(auto x:rt)
    {
        dfs2(x,x);
    }
    for(int i=1;i<=n;i++)
    {
        sum=0;dfs0(i);mm[i][0]=sum;
        sum=0;dfs1(i,1);mm[i][1]=sum;
    }
    //memset(mem,-1,sizeof mem);
    cout<<dfs(1,t,0)<<endl;
    return 0;
}