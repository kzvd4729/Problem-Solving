/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/10/2021 16:02                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1450 ms                                         memory_used: 97700 KB                             
*  problem: https://codeforces.com/contest/1557/problem/D
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
 const int N=6e5,inf=1e9;
 vector<pair<int,int> >v[N+2];
  void compress(vector<int>&a,int n)
{
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
   map<int,int>mp;
  for(int i=0;i<a.size();i++)mp[a[i]]=i+1;
   for(int i=1;i<=n;i++)
  {
    for(auto &x:v[i])
    {
      x.first=mp[x.first];
      x.second=mp[x.second];
    }
  }
}
  pair<int,int>sg[4*N+8],lz[4*N+8];
void tooLazy(int nd,int lo,int hi)
{
  sg[nd]=max(sg[nd],lz[nd]);
  if(lo!=hi)
  {
    lz[nd*2]=max(lz[nd*2],lz[nd]);
    lz[nd*2+1]=max(lz[nd*2+1],lz[nd]);
  }
  lz[nd]={0,0};
}
void upd(int nd,int lo,int hi,int lt,int rt,pair<int,int>vl)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]=max(lz[nd],vl);tooLazy(nd,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,vl);
  upd(nd*2+1,md+1,hi,lt,rt,vl);
   sg[nd]=max(sg[nd*2],sg[nd*2+1]);
}
pair<int,int>get(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return {0,0};
  if(lo>=lt&&hi<=rt)return sg[nd];
  int md=(lo+hi)/2;
  return max(get(nd*2,lo,md,lt,rt),get(nd*2+1,md+1,hi,lt,rt));
}
 int dp[N+2],pth[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  vector<int>a;
  for(int i=1;i<=m;i++)
  {
    int x,y,z;cin>>x>>y>>z;
    v[x].push_back({y,z});
     a.push_back(y);a.push_back(z);
  }
  compress(a,n);
   // for(int i=1;i<=n;i++)
  // {
  //   for(auto x:v[i])
  //   {
  //     cout<<x.first<<" "<<x.second<<" ";
  //   }
  //   cout<<endl;
  // }
   upd(1,1,N,1,N,{0,0});
    int mx=-1,id;
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p={0,0};
    for(auto x:v[i])p=max(p,get(1,1,N,x.first,x.second));
     dp[i]=p.first+1,pth[i]=p.second;
    for(auto x:v[i])upd(1,1,N,x.first,x.second,{dp[i],i});
     if(dp[i]>mx)mx=dp[i],id=i;
  }
  set<int>st;for(int i=1;i<=n;i++)st.insert(i);
   while(id)
  {
    st.erase(id);id=pth[id];
  }
  cout<<st.size()<<endl;
  for(auto x:st)cout<<x<<" ";cout<<endl;
   return 0;
}