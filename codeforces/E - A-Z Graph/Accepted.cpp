/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/02/2021 22:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 8900 KB                              
*  problem: https://codeforces.com/contest/1494/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  set<pair<int,int> >gl,sl,br;
  map<pair<int,int>,char>mp;
  for(int i=1;i<=m;i++)
  {
    char c;cin>>c;
    if(c=='+')
    {
      int u,v;char ch;cin>>u>>v>>ch;
      pair<int,int>p={u,v},q={v,u},e={min(u,v),max(u,v)};
       if(br.find(q)!=br.end())
      {
        if(mp[q]==ch)gl.insert(e);
        else sl.insert(e);
      }
      br.insert(p);
      mp[p]=ch;
    }
    else if(c=='-')
    {
      int u,v;cin>>u>>v;
      pair<int,int>p={u,v},q={v,u},e={min(u,v),max(u,v)};
       if(gl.find(e)!=gl.end())gl.erase(e);
      if(sl.find(e)!=sl.end())sl.erase(e);
       br.erase(p);
    }
    else
    {
      int k;cin>>k;
      if((int)gl.size())cout<<"YES\n";
      else if((k%2)&&(int)sl.size())cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
   return 0;
}