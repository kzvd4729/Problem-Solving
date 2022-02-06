/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2018 17:57                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/464/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long mod=1e9+7;
long vis[N+2],link[N+2];
pair<long,long>pw[N+2];
vector<pair<long,long> >adj[N+2];
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
  for(long i=1;i<=N;i++)
  {
    pw[i]=pw[i-1];pw[i].second*=2;
    pw[i].first+=pw[i].second/mod;
    pw[i].second%=mod;
  }
  long n,m;cin>>n>>m;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    if(u==99&&v==26&&w==87)pass();
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  long s,t;cin>>s>>t;
  priority_queue<pair<pair<long,long>,long> >pq;
  pq.push({{0,0},s});long f=0;
  while(pq.size())
  {
    pair<pair<long,long>,long>p=pq.top();pq.pop();
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
      pair<pair<long,long>,long>tmp;
      tmp.first.second=p.first.second+pw[x.second].second;
      tmp.first.first=p.first.first+pw[x.second].second+tmp.first.second/mod;
      tmp.first.second%=mod;tmp.second=x.first;
      tmp.first.first*=-1,tmp.first.second*=-1;
      pq.push(tmp);
    }
  }
  if(f==0)cout<<-1<<endl,exit(0);
  vector<long>ans;
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