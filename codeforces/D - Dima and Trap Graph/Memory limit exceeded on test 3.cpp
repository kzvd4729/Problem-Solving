/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2018 16:25                        
*  solution_verdict: Memory limit exceeded on test 3         language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/366/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e9;
int n,m,vis[N+2];
struct data
{ 
 int nd,lt,rt;
};
vector<data>adj[N+2];
vector<pair<int,int> >ans[N+2];
void bfs(void)
{
 queue<int>q;q.push(n);ans[n].push_back(make_pair(-inf,inf));
 while(q.size())
 {
  int node=q.front();q.pop();vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
   data p=adj[node][i];if(vis[p.nd])continue;
   q.push(p.nd);
   for(int j=0;j<ans[node].size();j++)
   {
    pair<int,int>pp;
    pp.first=max(ans[node][j].first,p.lt);
    pp.second=min(ans[node][j].second,p.rt);
    if(pp.second>=pp.first)ans[p.nd].push_back(pp);
   }
  }
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n>>m;
 while(m--)
 {
  int u,v,l,r;cin>>u>>v>>l>>r;
  data p;p.nd=v,p.lt=l,p.rt=r;
  adj[u].push_back(p);
  p.nd=u,adj[v].push_back(p);
 }
 bfs();
 int pr=0;
 for(int i=0;i<ans[1].size();i++)
  pr=max(pr,ans[1][i].second-ans[1][i].first+1);
 if(pr==0)cout<<"Nice work, Dima!"<<endl;
 else cout<<pr<<endl;
 return 0;
}