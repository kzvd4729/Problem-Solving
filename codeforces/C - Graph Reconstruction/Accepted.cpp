/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2018 03:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1152 ms                                         memory_used: 31100 KB                             
*  problem: https://codeforces.com/contest/329/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long st;
int last,n,m,rt;
set<int>adj[N+2];
set<int>zr;
vector<pair<int,int> >ed;
void print(void)
{
    cout<<endl;
    for(auto x:ed)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    exit(0);
}
void dfs(int node)
{
    if(zr.size()==0)
    {
        if(adj[rt].find(last)==adj[rt].end())
        {
            ed.push_back({rt,last});
            print();
        }
        return ;
    }
    vector<int>tmp,go;
    while(zr.size())
    {
        if(go.size()==5)break;
        int p=*zr.begin();
        if(adj[node].find(p)==adj[node].end())
            go.push_back(p);
        else tmp.push_back(p);
        zr.erase(p);
    }
    for(auto x:tmp)zr.insert(x);
    for(auto x:go)zr.insert(x);
    int lst=last;
    for(auto x:go)
    {
        ed.push_back({node,x});
        adj[node].insert(x);
        adj[x].insert(node);
        last=x;
        if(ed.size()==m)print();
        zr.erase(x);
        dfs(x);
        zr.insert(x);
        ed.pop_back();
        adj[node].erase(x);
        adj[x].erase(node);
        last=lst;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     st=clock();
     cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].insert(v);adj[v].insert(u);
    }
    for(int i=1;i<=n;i++)
    {
        rt=i;
        zr.clear();ed.clear();
        for(int i=1;i<=n;i++)
        {
            if(i!=rt)zr.insert(i);
        }
        dfs(rt);
    }
    cout<<-1<<endl;
    return 0;
}