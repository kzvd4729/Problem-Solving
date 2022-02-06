/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2018 19:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 8500 KB                              
*  problem: https://codeforces.com/contest/766/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e5;
map<string,int>mp;pair<int,int>par[N+2];
pair<int,int>_find(int x)
{
  if(x!=par[x].first)
  {
    int parity=par[x].second;
    par[x]=_find(par[x].first);
    par[x].second^=parity;
  }
  return par[x];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;mp[s]=++cnt;
    par[i]={i,0};
  }
  while(m--)
  {
    int ty;string a,b;cin>>ty>>a>>b;
    pair<int,int>r1=_find(mp[a]),r2=_find(mp[b]);
    if(ty==1)
    {
      if(r1.first==r2.first&&r1.second!=r2.second)
        cout<<"NO"<<endl;
      else
      {
        cout<<"YES"<<endl;
        par[r1.first]={r2.first,r1.second^r2.second};
      }
    }
    else
    {
      if(r1==r2)
        cout<<"NO"<<endl;
      else
      {
        cout<<"YES"<<endl;
        par[r1.first]={r2.first,r1.second^r2.second^1};
      }
    }
  }
  while(q--)
  {
    string a,b;cin>>a>>b;
    pair<int,int>r1=_find(mp[a]),r2=_find(mp[b]);
    if(r1.first!=r2.first)cout<<3<<endl;
    else if(r1.second==r2.second)cout<<1<<endl;
    else cout<<2<<endl;
  }
  return 0;
}