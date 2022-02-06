/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 17:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 22600 KB                             
*  problem: https://codeforces.com/contest/1266/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long out[N+2],in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n>>m;
  while(m--)
  {
    long u,v,w;cin>>u>>v>>w;
    if(u==1)out[v]+=w;else if(v==1)in[u]+=w;
    else out[v]+=w,in[u]+=w;
  }
  for(long i=1;i<=n;i++)
  {
    long mn=min(in[i],out[i]);in[i]-=mn,out[i]-=mn;
  }
  priority_queue<pair<long,long> >pq;
  for(long i=1;i<=n;i++)
    pq.push({out[i],i});
  vector<vector<long> >ed;
  for(long i=1;i<=n;i++)
  {
    while(pq.size())
    {
      if(!in[i])break;
      pair<long,long>p=pq.top();pq.pop();
      long mn=min(in[i],p.first);
       p.first-=mn;out[p.second]-=mn;
      if(p.first)pq.push(p);
      if(mn)ed.push_back({i,p.second,mn});
      in[i]-=mn;
    }
  }
  long cnt=ed.size();
   for(long i=1;i<=n;i++)if(out[i])cnt++;
  for(long i=1;i<=n;i++)if(in[i])cnt++;
   cout<<cnt<<endl;
  for(auto x:ed)
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
  for(long i=1;i<=n;i++)
    if(out[i])cout<<1<<" "<<i<<" "<<out[i]<<"\n";
  for(long i=1;i<=n;i++)
    if(in[i])cout<<i<<" "<<1<<" "<<in[i]<<"\n";
   return 0;
}