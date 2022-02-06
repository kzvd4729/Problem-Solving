/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2018 14:12                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/697/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long q,ty,u,v,w;
map<pair<long,long>,long>mp;
long raise(long u,long v,long w)
{
  long sum=0;
  if(u<v)swap(u,v);
   while(true)
  {
    long c1=64-__builtin_clzll(u);
    long c2=64-__builtin_clzll(v);
    if(c1==c2)break;
    sum+=mp[{u/2,u}];
    mp[{u/2,u}]+=w;
    u/=2;
  }
  while(true)
  {
    if(u==v)break;
    sum+=mp[{u/2,u}];
    sum+=mp[{v/2,v}];
    mp[{u/2,u}]+=w;
    mp[{v/2,v}]+=w;
    u/=2;
    v/=2;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>q;
  while(q--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>u>>v>>w;
      raise(u,v,w);
    }
    else
    {
      cin>>u>>v;
      cout<<raise(u,v,0)<<endl;
    }
  }
  return 0;
}