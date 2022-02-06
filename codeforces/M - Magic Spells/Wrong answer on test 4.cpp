/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2021 20:35                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17 (64)                          
*  run_time: 1200 ms                                         memory_used: 20000 KB                             
*  problem: https://codeforces.com/gym/102966/problem/M
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long N=1e6,inf=1e9,mod=998244353;
 long pos[2520+2][20+2][20+2];
long ln,ls,dp[2520][20+2][20+2];
 long dfs(long i,long l)
{
  if(i==ln)return (l==ls);
  if(dp[i][ls][l]!=-1)return dp[i][ls][l];
  long ret=0;
  for(long j=1;j<=20;j++)
  {
    if(pos[i][l][j])
      ret=(ret+dfs(i+1,j))%mod;
  }
  return dp[i][ls][l]=ret;
};
 vector<vector<long> >multiply(vector<vector<long> >a,vector<vector<long> >b)
{
  vector<vector<long> >ret(20+2);
  for(long i=0;i<20+2;i++)
  {
    for(long j=0;j<20+2;j++)ret[i].push_back(0);
  }
   for(long i=1;i<=20;i++)
  {
    for(long j=1;j<=20;j++)
    {
      for(long k=1;k<=20;k++)
      {
        for(long l=1;l<=20;l++)
        {
          if(pos[ln][j][k])
          {
            ret[i][l]=(ret[i][l]+1LL*a[i][j]*b[k][l])%mod;
            //if(ret[i][l])cout<<ret[i][l]<<" "<<a[i][j]<<" "<<b[k][l]<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
          }
        }
      }
    }
  }
  return ret;
}
vector<vector<long> >multiply2(vector<vector<long> >a,vector<vector<long> >b,long bg)
{
  vector<vector<long> >ret(20+2);
  for(long i=0;i<20+2;i++)
  {
    for(long j=0;j<20+2;j++)ret[i].push_back(0);
  }
   for(long i=bg;i<=bg;i++)
  {
    for(long j=1;j<=20;j++)
    {
      for(long k=1;k<=20;k++)
      {
        for(long l=1;l<=20;l++)
        {
          if(pos[ln][j][k])
          {
            ret[i][l]=(ret[i][l]+1LL*a[i][j]*b[k][l])%mod;
            //if(ret[i][l])cout<<ret[i][l]<<" "<<a[i][j]<<" "<<b[k][l]<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
          }
        }
      }
    }
  }
  return ret;
}
vector<vector<long> >pw[100+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long m,q;cin>>m>>q;
  vector<vector<long> >v;vector<long>pp;
  for(long i=1;i<=m;i++)
  {
    char c1,c2;cin>>c1>>c2;
    long a=c1-'a'+1,b=c2-'a'+1,p;cin>>p;
     v.push_back({a,b,p});
    pp.push_back(p);
  }
  long lcm;
  sort(pp.begin(),pp.end());
  pp.erase(unique(pp.begin(),pp.end()),pp.end());
  for(lcm=1; ;lcm++)
  {
    long f=0;
    for(auto x:pp)f+=lcm%x;
    if(f==0)break;
  }
  lcm=2520;
  for(auto x:v)
  {
    for(long k=0; ;k++)
    {
      long p=k*x[2]+1;
      if(p>lcm)break;
      pos[p][x[0]][x[1]]=1;
    }
  }
  ln=lcm;
  vector<vector<long> >cnt;
  cnt.resize(20+2);
  for(long i=0;i<20+2;i++)
  {
    for(long j=0;j<20+2;j++)cnt[i].push_back(0);
  }
   memset(dp,-1,sizeof dp);
  ln=lcm;
  for(long i=1;i<=20;i++)
  {
    for(long j=1;j<=20;j++)
    {
      ls=j;
      cnt[i][j]=dfs(1,i);
      //if(cnt[i][j])cout<<i<<" "<<j<<" "<<cnt[i][j]<<endl;
    }
  }
  ln=lcm;
  pw[0]=cnt;
  for(long i=1;i<=60;i++)pw[i]=multiply(pw[i-1],pw[i-1]);
  while(q--)
  {
    char c1,c2;cin>>c1>>c2;
    long a=c1-'a'+1,b=c2-'a'+1;
    long l;cin>>l;
     ln=lcm;
    vector<vector<long> >ret;
    long p=l/lcm;
    for(long i=0;i<60;i++)
    {
      if((p&(1LL<<i)))
      {
        if((long)ret.size()==0)ret=pw[i];
        else ret=multiply(ret,pw[i]);
      }
    }
    ln=l%lcm;
    ls=b;
    vector<vector<long> >rem(20+2);
    for(long i=0;i<20+2;i++)
    {
      for(long j=0;j<20+2;j++)rem[i].push_back(0);
    }
     if(ln==0)
    {
      cout<<ret[a][b]<<'\n';continue;
    }
     for(long i=1;i<=ln;i++)
    {
      for(long j=1;j<=20;j++)
        dp[i][ls][j]=-1;
    }
     for(long i=1;i<=20;i++)
      rem[i][ls]=dfs(1,i);
     if(l/lcm==0)
    {
      cout<<rem[a][b]<<'\n';continue;
    }
     ret=multiply(ret,rem);
    cout<<ret[a][b]<<'\n';
  }
  return 0;
}