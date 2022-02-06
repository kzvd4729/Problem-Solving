/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 21:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 16700 KB                             
*  problem: https://codeforces.com/contest/1154/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  set<pair<int,int> >st,dt;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert({x,i});
    dt.insert({i,x});
  }
  dt.insert({0,0});dt.insert({n+1,n+1});
  int tr=1;
  while(true)
  {
    if(st.size()==0)break;
    pair<int,int>p=*st.rbegin();st.erase(p);
    dt.erase({p.second,p.first});
    ans[p.second]=tr;
    pair<int,int>q={p.second,p.first};
    for(int i=1;i<=k;i++)
    {
      auto it=dt.lower_bound(q);
      if(it->first>n)break;
       ans[it->first]=tr;dt.erase(*it);
      st.erase({it->second,it->first});
    }
    for(int i=1;i<=k;i++)
    {
      auto it=dt.lower_bound(q);
      it--;
      if(it->first<1)break;
       ans[it->first]=tr;dt.erase(*it);
      st.erase({it->second,it->first});
    }
    if(tr==1)tr=2;
    else tr=1;
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i];
  cout<<endl;
  return 0;
}