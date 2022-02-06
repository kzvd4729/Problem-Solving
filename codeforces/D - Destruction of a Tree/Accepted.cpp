/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2018 14:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 37600 KB                             
*  problem: https://codeforces.com/contest/964/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
  int n,x,root,dis[200005],vis[200005];
set<int>adj[200005];
set<pair<int,int> >st;
vector<int>print;
  void bfs(void)
{
queue<int>q;
q.push(root);
while(q.size())
{
int u=q.front();
q.pop();
set<int>::iterator tt;
for(tt=adj[u].begin();tt!=adj[u].end();tt++)
{
int xx=*tt;
if(xx==root||dis[xx])continue;
dis[xx]=dis[u]+1;
q.push(xx);
}
}
}
  void _delete(int xx)
{
print.push_back(xx);
set<int>::iterator tt;
for(tt=adj[xx].begin();tt!=adj[xx].end();tt++)
{
int z=*tt;
adj[z].erase(xx);
if(vis[z]&&adj[z].size()%2==0)_delete(z);
}
}
      int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
  cin>>n;
for(int i=1;i<=n;i++)
{
cin>>x;
if(x==0)root=i;
else
{
adj[i].insert(x);
adj[x].insert(i);
}
}
  bfs();
set<pair<int,int> >::iterator it; 
for(int i=1;i<=n;i++)st.insert(make_pair(-dis[i],i));
  for(it=st.begin();it!=st.end();it++)
{
int xx=it->second;
vis[xx]=1;
if((adj[xx].size()*1LL)%2)continue;
_delete(xx);
}
 if(print.size()!=n)cout<<"NO"<<endl,exit(0);
cout<<"YES"<<endl;
for(int i=0;i<print.size();i++)cout<<print[i]<<"\n";
 return 0;
}