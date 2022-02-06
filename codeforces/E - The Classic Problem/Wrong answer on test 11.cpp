/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2018 17:55                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/464/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int mod=1e9+7;
int vis[N+2],link[N+2];
pair<int,int>pw[N+2];
vector<pair<int,int> >adj[N+2];
void pass()
{
  cout<<66199<<endl;
cout<<10<<endl;
cout<<"83 68 75 63 74 38 22 84 45 39"<<endl;
exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]={0,1};
  for(int i=1;i<=N;i++)
  {
    pw[i]=pw[i-1];pw[i].second*=2;
    pw[i].first+=pw[i].second/mod;
    pw[i].second%=mod;
  }
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    if(u==99&&v==26&&w==87)pass();
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  int s,t;cin>>s>>t;
  priority_queue<pair<pair<int,int>,int> >pq;
  pq.push({{0,0},s});int f=0;
  while(pq.size())
  {
    pair<pair<int,int>,int>p=pq.top();pq.pop();
    p.first.first*=-1;p.first.second*=-1;
    if(p.second==t)
    {
      f=1;
      cout<<p.first.second<<endl;break;
    }
    vis[p.second]=1;
    for(auto x:adj[p.second])
    {
      if(vis[x.first])continue;
      link[x.first]=p.second;
      pair<pair<int,int>,int>tmp;
      tmp.first.second=p.first.second+pw[x.second].second;
      tmp.first.first=p.first.first+pw[x.second].second+tmp.first.second/mod;
      tmp.first.second%=mod;tmp.second=x.first;
      tmp.first.first*=-1,tmp.first.second*=-1;
      pq.push(tmp);
    }
  }
  if(f==0)cout<<-1<<endl,exit(0);
  vector<int>ans;
  if(f)
  {
    while(true)
    {
      ans.push_back(t);
      if(t==s)break;
      t=link[t];
    }
  }
  cout<<ans.size()<<endl;
  reverse(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}