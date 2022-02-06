/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/28/2018 22:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1082/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
const int inf=1e9;
vector<pair<int,int> >ed,one,els;
vector<int>adj[N+2];
int n,dis[N+2];
int bfs(int nd)
{
  for(int i=1;i<=n;i++)dis[i]=inf;int ret=0;
  queue<int>q;q.push(nd);dis[nd]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(dis[x]==inf)
      {
        dis[x]=dis[u]+1;
        q.push(x);ret=max(ret,dis[x]);
      }
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;int sum=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sum+=x;
    if(x==1)
      one.push_back({x,i});
    else els.push_back({x,i});
  }
  if(sum<(n-1)*2)cout<<"NO"<<endl,exit(0);
  sort(els.begin(),els.end());
   int last=-1;
  while(els.size())
  {
    pair<int,int>p=els.back();
    els.pop_back();int xx;
    if(last!=-1)
    {
      ed.push_back({p.second,last});
      xx=p.first-2;
    }
    else xx=p.first-1;
    while(xx--)
    {
      if(one.size()>1)
      {
        ed.push_back({one.back().second,p.second});
        one.pop_back();
      }
      else break;
    }
    last=p.second;
  }
  if(one.size())
    ed.push_back({one[0].second,last});
  for(auto x:ed)
  {
    adj[x.first].push_back(x.second);
    adj[x.second].push_back(x.first);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,bfs(i));
  cout<<"YES"<<" "<<ans<<endl;
  cout<<ed.size()<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}