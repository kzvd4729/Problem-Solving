/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-15 23:39:50                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12494
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+9;
const int N=2e2;
const int b=31;
int t;
unordered_map<long,int>mp;
long inv,bb[N+2];
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
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp.max_load_factor(0.25);
  mp.reserve(512);

  bb[1]=b;
  for(int i=2;i<=N;i++)
    bb[i]=(bb[i-1]*b)%mod;
  inv=bigmod(b,mod-2,mod);

  cin>>t;
  while(t--)
  {
    cin>>s;int ans=0;
    mp.clear();
    for(int i=0;i<s.size();i++)
    {
      string tmp;long hs=0;
      for(int j=i;j<s.size();j++)
      {
        tmp.push_back(s[j]);
        hs=(hs+bb[j-i+1]*(long)s[j])%mod;
        long ths=hs;int f=0;
        if(mp[ths])f=1;
        for(int k=0;k<tmp.size();k++)
        {
          ths=(ths*inv)%mod;
          ths=(ths-(long)tmp[k]+mod)%mod;
          ths=(ths+(long)tmp[k]*bb[j-i+1])%mod;
          if(mp[ths])f=1;
          if(f)break;
        }
        if(!f)ans++;
        mp[hs]=1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}