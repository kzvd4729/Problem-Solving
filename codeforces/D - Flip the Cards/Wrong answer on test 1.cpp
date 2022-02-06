/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2021 00:03                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/1503/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  void no(){cout<<-1<<endl;exit(0);}
  int a[N+2],b[N+2],vs[N+2];
vector<pair<int,int> >ad[N+2];
  vector<int>scc;
void dfs(int nd)
{
  vs[nd]=1;
  for(auto x:ad[nd])
  {
    if(vs[x.first])continue;
    scc.push_back(x.second);
    dfs(x.first);
  }
}
 int solve(vector<int>scc)
{
  set<pair<int,int> >st;
  for(int i=0;i<(int)scc.size();i++)
  {
    st.insert({a[scc[i]],scc[i]});
    st.insert({b[scc[i]],scc[i]});
  }
   int ans=0;
  pair<int,int>p=*st.begin();
  int l1=-1,r1=inf,l2=-1,r2=inf;
   l1=p.first;int id=p.second;
  if(a[id]==l1)r2=b[id];else r2=a[id],ans++;
  st.erase({a[id],id});st.erase({b[id],id});
   while(st.size())
  {
    pair<int,int>p=*st.begin();
    int id=p.second;
      if(p.first>=l1 && p.first<=r1 && (p.first<l2 || p.first>r2))
    {
      //fixed in up;
      if(p.first==b[id])ans++,swap(a[id],b[id]);
      st.erase({a[id],id});
      st.erase({b[id],id});
       l1=a[id];
      r2=b[id];
      continue;
    }
    if(p.first>=l2 && p.first<=r2 && (p.first<l1 || p.first>r1))
    {
      //fixed in dw;
      if(p.first==a[id])ans++,swap(a[id],b[id]);
      st.erase({a[id],id});
      st.erase({b[id],id});
       r1=a[id];
      l2=b[id];
      continue;
    }
    p=*st.rbegin();
    id=p.second;
      if(p.first>=l1 && p.first<=r1 && (p.first<l2 || p.first>r2))
    {
      //fixed in up;
      if(p.first==b[id])ans++,swap(a[id],b[id]);
      st.erase({a[id],id});
      st.erase({b[id],id});
       r1=a[id];
      l2=b[id];
      continue;
    }
    if(p.first>=l2 && p.first<=r2 && (p.first<l1 || p.first>r1))
    {
      //fixed in dw;
      if(p.first==a[id])ans++,swap(a[id],b[id]);
      st.erase({a[id],id});
      st.erase({b[id],id});
       l1=a[id];
      r2=b[id];
      continue;
    }
    return inf;
   }
  return min(ans,(int)scc.size()-ans);
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i]>>b[i];
    if(a[i]<=n && b[i]<=n)no();
    if(a[i]>n && b[i]>n)no();
     int x=a[i],y=b[i];
    if(x>y)swap(x,y);
     ad[x].push_back({i,n+n-y+1});
    ad[n+n-y+1].push_back({i,x});
   }
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;
    scc.clear();dfs(i);
     sort(scc.begin(),scc.end());
    scc.erase(unique(scc.begin(),scc.end()),scc.end());
     for(auto x:scc)cout<<x<<" ";cout<<endl;
     ans+=solve(scc);
  }
   cout<<ans<<endl;
   return 0;
}