/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-15 23:55:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 510                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12494
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const long mdd=1e9+9;
const int N=2e2;
const int b=39;
const int c=31;
int t;
struct pair_hash
{
  inline std::size_t operator()(const std::pair<int,int> & v) const
  {
    return v.first*31+v.second;
  }
};
unordered_set<pair<int,int>,pair_hash>mp;
long inv,ivn,bb[N+2],cc[N+2];
string s;
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

//  mp.max_load_factor(0.25);
//  mp.reserve(512);

  bb[1]=b;
  for(int i=2;i<=N;i++)
    bb[i]=(bb[i-1]*b)%mod;
  inv=bigmod(b,mod-2,mod);

  cc[1]=c;
  for(int i=2;i<=N;i++)
    cc[i]=(cc[i-1]*c)%mdd;
  ivn=bigmod(c,mdd-2,mdd);

  cin>>t;
  while(t--)
  {
    cin>>s;int ans=0;
    mp.clear();
    for(int i=0;i<s.size();i++)
    {
      string tmp;long hs=0,sh=0;
      for(int j=i;j<s.size();j++)
      {
        tmp.push_back(s[j]);
        hs=(hs+bb[j-i+1]*(long)s[j])%mod;
        sh=(sh+cc[j-i+1]*(long)s[j])%mdd;
        long ths=hs,tsh=sh;int f=0;
        if(mp.count({ths,tsh}))f=1;
        for(int k=0;k<tmp.size();k++)
        {
          ths=(ths*inv)%mod;
          ths=(ths-(long)tmp[k]+mod)%mod;
          ths=(ths+(long)tmp[k]*bb[j-i+1])%mod;

          tsh=(tsh*ivn)%mdd;
          tsh=(tsh-(long)tmp[k]+mdd)%mdd;
          tsh=(tsh+(long)tmp[k]*cc[j-i+1])%mdd;

          if(mp.count({ths,tsh}))f=1;
          if(f)break;
        }
        if(!f)ans++;
        mp.insert({hs,sh});
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}