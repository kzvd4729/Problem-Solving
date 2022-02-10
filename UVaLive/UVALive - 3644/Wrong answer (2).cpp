/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 16:05:56                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3644
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int par[N+2];
int get(int x)
{
  if(par[x]==x)return x;
  return par[x]=get(par[x]);
}
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int u,v;vector<pair<int,int> >ed;
  while(cin>>u)
  {
    if(u==-1)assert(0);
    ed.clear(),mp.clear();
    cin>>v;ed.push_back({u,v});
    while(cin>>u)
    {
      if(u==-1)break;
      cin>>v;ed.push_back({u,v});
    }
    for(int i=0;i<=N;i++)par[i]=i;
    int cnt=0;
    for(auto x:ed)
    {
      int u=min(x.first,x.second),v=max(x.first,x.second);
      if(mp[{u,v}]||u==v)assert(0);
      mp[{u,v}]=1;
      if(u<0||v<0||u>N||v>N)assert(0);

      int r1=get(x.first),r2=get(x.second);
      if(r1==r2)cnt++;
      else par[r1]=r2;
    }
    cout<<cnt<<endl;
  }
  return 0;
}