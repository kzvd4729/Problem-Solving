/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2021 22:09                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 3868 ms                                         memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/1285/problem/E
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
const int N=4e5,inf=1e9,mod=1e9+7;
  pair<int,int>p[N+2];
multiset<int>st[N+2];
int dp[N+2],mx[N+2];
   int seg[4*N+8];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lt>rt)return -inf;
  if(lo>rt||hi<lt)return -inf;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  int p1=get(node*2,lo,md,lt,rt);
  int p2=get(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>v;
    for(int i=1;i<=n;i++)
    {
      cin>>p[i].first>>p[i].second;
      v.push_back(p[i].first);v.push_back(p[i].second);
    }
     sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     memset(seg,0,sizeof seg);
     map<int,int>mp;
    for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
     for(int i=1;i<=n;i++)p[i].first=mp[p[i].first],p[i].second=mp[p[i].second];
      sort(p+1,p+n+1);
    // for(int i=1;i<=n;i++)cout<<p[i].first<<" "<<p[i].second<<endl;
    // cout<<endl<<endl;
      int m=v.size();
    for(int i=1;i<=m;i++)st[i].clear();
    for(int i=1;i<=n;i++)st[p[i].first].insert(p[i].second);
    for(int i=1;i<=m;i++)st[i].insert(i-1);
      for(int i=m;i>=1;i--)
    {
      dp[i]=*st[i].rbegin();
      dp[i]=max(dp[i],get(1,1,m,i,dp[i]));
       upd(1,1,m,i,dp[i]);
    }
         for(int i=1;i<=m;i++)mx[i]=max(mx[i-1],*st[i].rbegin());
      // cout<<endl;
    // for(int i=1;i<=m;i++)cout<<mx[i]<<" ";cout<<endl;
    // for(int i=1;i<=m;i++)cout<<dp[i]<<" ";cout<<endl;
      int ans=0,tl=p[1].second;
    for(int i=2;i<=n;i++)
    {
      if(p[i].first<=tl)tl=max(tl,p[i].second);
      else ans++,tl=p[i].second;
    }
    ans++;
      //cout<<ans<<endl;
    int prn=ans;
     for(int i=1;i<=n;i++)
    {
      int l=p[i].first,r=p[i].second;
       int cv=mx[l-1];st[l].erase(st[l].find(r));
      cv=max(cv,*st[l].rbegin());st[l].insert(r);
        if(cv>l)cv=max(cv,get(1,1,m,l+1,cv));
      if(cv>=r)continue;
        int cr=-1;
      if(cv>=l)cr++,cv++;
      else cv=l+1;
        while(cv<=r)
      {
        if(dp[cv]<cv)cv++;
        else cr++,cv=dp[cv]+1;
       }
       prn=max(prn,ans+cr);
    }
    cout<<prn<<endl;
  }
  return 0;
}