/****************************************************************************************
*  @author: kzvd4729                                         created: 17-02-2019 21:55:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.48 sec                                        memory_used: 35.2M                                
*  problem: https://www.codechef.com/COOK103A/problems/SECPASS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/**************** Hash ******************/
const long mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
long pw1[N+2],pw2[N+2];
void Call(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%mod1;
    pw2[i]=(pw2[i-1]*b2)%mod2;
  }
}
struct Hash
{
  string s;vector<pair<long,long> >v;
  pair<long,long>make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%mod1;
      hs2=(hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<long,long>segment(int lt,int rt)
  {
    long x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=(x-(v[lt-1].first*pw1[rt-lt+1])%mod1+mod1)%mod1;
    y=(y-(v[lt-1].second*pw2[rt-lt+1])%mod2+mod2)%mod2;
    return {x,y};
  }
};
/////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;Call(N);
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    Hash hs;hs.s=s;hs.v.clear();
    hs.make_hash();
    int cnt=0;
    for(int i=0;i<n;i++)
      if(s[i]==s[0])cnt++;
    if(cnt==1)
    {
      cout<<s<<"\n";continue;
    }
    int lo=0,hi=n-1,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      pair<long,long>p=hs.segment(0,md);
      int now=1;
      for(int i=1; ;i++)
      {
        if(i+md>=n)break;
        if(hs.segment(i,i+md)==p)now++;
      }
      if(now>=cnt)lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
    {
      pair<long,long>p=hs.segment(0,md);
      int now=1;
      for(int i=1; ;i++)
      {
        if(i+md>=n)break;
        if(hs.segment(i,i+md)==p)now++;
      }
      if(now==cnt)
      {
        for(int i=0;i<=md;i++)
          cout<<s[i];
        cout<<"\n";break;
      }
    }
  }
  return 0;
}