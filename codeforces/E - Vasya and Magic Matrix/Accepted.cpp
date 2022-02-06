/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2020 21:58                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1949 ms                                         memory_used: 51300 KB                             
*  problem: https://codeforces.com/contest/1042/problem/E
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
#define long long long 
using namespace std;
const int N=1e3,mod=998244353;
int a[N+2][N+2],n,m;
void compress()
{
  vector<int>v;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)v.push_back(a[i][j]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)a[i][j]=mp[a[i][j]];
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
vector<pair<int,int> >po[N*N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  }
  compress();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)po[a[i][j]].push_back({i,j});
  }
  int r,c;cin>>r>>c;int mx=a[r][c];
  long print=0;
   long ex=0,yy=0,y=0,cnt=0;
  for(int i=1;i<=mx;i++)
  {
    long tmp=0;int j=0;
    for(auto x:po[i])
    {
      long now=0,a=x.first;
      now=(ex+yy+((a*a)%mod)*cnt)%mod;
      now=(now-((2LL*a*y)%mod)+mod)%mod;
       now=(now*big(cnt,mod-2))%mod;
       if(x.first==r&&x.second==c)print+=now;
      tmp=(tmp+now)%mod;
    }
    ex=(ex+tmp)%mod;cnt+=po[i].size();
    for(auto x:po[i])
    {
      yy=(yy+1LL*x.first*x.first)%mod;
      y=(y+x.first)%mod;
    }
  }
  ex=0,yy=0,y=0,cnt=0;
  for(int i=1;i<=mx;i++)
  {
    long tmp=0;int j=0;
    for(auto x:po[i])
    {
      long now=0,a=x.second;
      now=(ex+yy+((a*a)%mod)*cnt)%mod;
      now=(now-((2LL*a*y)%mod)+mod)%mod;
       now=(now*big(cnt,mod-2))%mod;
       if(x.first==r&&x.second==c)print+=now;
      tmp=(tmp+now)%mod;
    }
    ex=(ex+tmp)%mod;cnt+=po[i].size();
    for(auto x:po[i])
    {
      yy=(yy+1LL*x.second*x.second)%mod;
      y=(y+x.second)%mod;
    }
  }
  cout<<print%mod<<endl;
  return 0;
}