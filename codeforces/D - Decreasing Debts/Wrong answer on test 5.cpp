/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 17:56                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 16800 KB                             
*  problem: https://codeforces.com/contest/1266/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int out[N+2],in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    if(u==1)out[v]+=w;else if(v==1)in[u]+=w;
    else out[v]+=w,in[u]+=w;
  }
  for(int i=1;i<=n;i++)
  {
    int mn=min(in[i],out[i]);in[i]-=mn,out[i]-=mn;
  }
  priority_queue<pair<int,int> >pq;
  for(int i=1;i<=n;i++)
    pq.push({out[i],i});
  vector<vector<int> >ed;
  for(int i=1;i<=n;i++)
  {
    while(pq.size())
    {
      if(!in[i])break;
      pair<int,int>p=pq.top();pq.pop();
      int mn=min(in[i],p.first);
       p.first-=mn;out[p.second]-=mn;
      if(p.first)pq.push(p);
      ed.push_back({i,p.second,mn});
      in[i]-=mn;
    }
  }
  int cnt=ed.size();
   for(int i=1;i<=n;i++)if(out[i])cnt++;
  for(int i=1;i<=n;i++)if(in[i])cnt++;
   cout<<cnt<<endl;
  for(auto x:ed)
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
  for(int i=1;i<=n;i++)
    if(out[i])cout<<1<<" "<<i<<" "<<out[i]<<"\n";
  for(int i=1;i<=n;i++)
    if(in[i])cout<<i<<" "<<1<<" "<<in[i]<<"\n";
   return 0;
}