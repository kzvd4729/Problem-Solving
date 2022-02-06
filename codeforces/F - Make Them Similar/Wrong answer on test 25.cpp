/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2019 01:13                        
*  solution_verdict: Wrong answer on test 25                 language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 12900 KB                             
*  problem: https://codeforces.com/contest/1257/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
 const int mod=1000001011;
const int b=193;
int pw[N+2];
void cal(int n)
{
  pw[0]=1;
  for(int i=1;i<=n;i++)
    pw[i]=(1LL*pw[i-1]*b)%mod;
}
struct hsh
{
  vector<int>v;
  int makeHash(void)
  {
    int hs=0;
    for(auto x:v)
      hs=(1LL*hs*b+x)%mod;
    return hs;
  }
  void clear()
  {
    v.clear();
  }
}hs;
 map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tt=(1<<30)-1,a,b;b=tt;
  for(int i=0;i<15;i++)b^=(1<<i);a=b^tt;
   int n;cin>>n;cal(n);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x&a;
    for(int j=15;j<30;j++)
      if(x&(1<<j))bb[i]|=(1<<(j-15));
   }
  for(int i=0;i<(1<<15);i++)
  {
    for(int j=1;j<=n;j++)
      hs.v.push_back(__builtin_popcount((i^bb[j])));
    //cout<<hs.makeHash()<<endl;
    mp[hs.makeHash()]=i;hs.clear();
  }
  for(int i=0;i<(1<<15);i++)
  {
    int mx=0;vector<int>now;
    for(int j=1;j<=n;j++)
    {
      mx=max(mx,__builtin_popcount((i^aa[j])));
      now.push_back(__builtin_popcount((i^aa[j])));
    }
    for(int m=mx;m<=30;m++)
    {
      for(auto x:now)
        hs.v.push_back(m-x);
      int h=hs.makeHash();
      if(mp.find(h)!=mp.end())
      {
        auto it=mp.find(h);
        int ans=i;
        for(int p=0;p<15;p++)
        {
          if((it->second&(1<<p)))
            ans|=(1<<(15+p));
        }
        cout<<ans<<endl,exit(0);
      }
      hs.clear();
    }
  }
  cout<<-1<<endl;
  return 0;
}