/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 19:41                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 280 ms                                          memory_used: 209100 KB                            
*  problem: https://codeforces.com/contest/1472/problem/F
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
const int N=2e6+2000,inf=1e9,mod=1e9+7;
 pair<int,int>p[N+2];
int dp[N+2][2][2],n,vs[N+2][2+2];
 int dfs(int c,int f1,int f2)
{
  //cout<<c<<" "<<f1<<" "<<f2<<endl;
  if(c>n)
  {
    return ((f1==0) && (f2==0));
  }
   if(f1 && vs[c][1])return 0;
  if(f2 && vs[c][2])return 0;
   if(vs[c][1])f1=1;
  if(vs[c][2])f2=1;
   if(dp[c][f1][f2]!=-1)return dp[c][f1][f2];
   int ret=0;
  if((f1==0) && (f2==0))
  {
    ret|=dfs(c+1,0,0);
    ret|=dfs(c+1,1,1);
  }
  if((f1==0) && (f2==1))
  {
    ret|=dfs(c+1,1,0);
  }
  if((f1==1) && (f2==0))
  {
    ret|=dfs(c+1,0,1);
  }
  if((f1==1) && (f2==1))
  {
    ret|=dfs(c+1,0,0);
  }
  return dp[c][f1][f2]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;vector<int>v;
    int mx=0;
    for(int i=1;i<=m;i++)
    {
      cin>>p[i].first>>p[i].second;
      swap(p[i].first,p[i].second);
      v.push_back(p[i].first);
      mx=max(mx,p[i].first);
    }
     //cout<<"HERE"<<endl;
    v.push_back(n);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     int ls=0,sub=0;map<int,int>mp;
    for(auto x:v)
    {
      int rm=x;x-=sub;
       int th=10;
      if((x-ls)%2)th=9;
       if(x>ls+th)
      {
        ls=ls+th;
        sub+=x-ls;
      }
      else
      {
        ls=x;
      }
      mp[rm]=ls;
    }
     for(int i=1;i<=m;i++)
      p[i].first=mp[p[i].first];
      n=ls;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=-1;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=2;j++)vs[i][j]=0;
    }
    for(int i=1;i<=m;i++)
      vs[p[i].first][p[i].second]=1;
     //for(int i=1;i<=m;i++)cout<<p[i].first<<" "<<p[i].second<<endl;
     if(dfs(1,0,0))cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
  return 0;
}