/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 20:58:06                      
*  solution_verdict: Compilation Error                       language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/APRIL19A/problems/KLPM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int b1=193,b2=307;
const long m1=1000001011,m2=1000009999;
long pw1[N+2],pw2[N+2];
void power_cal(void)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=N;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%m1;
    pw2[i]=(pw2[i-1]*b2)%m2;
  }
}
struct _hash
{
  string s;vector<pair<long,long> >v;
  void make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%m1;
      hs2=(hs2*b2+x)%m2;
      v.push_back({hs1,hs2});
    }
  }
  pair<long,long>segment(int l,int r)
  {
    long x=v[r].first,y=v[r].second;
    if(!l)return {x,y};
    x=(x-(v[l-1].first*pw1[r-l+1])%m1+m1)%m1;
    y=(y-(v[l-1].second*pw2[r-l+1])%m2+m2)%m2;
    return {x,y};
  }
};
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  power_cal();string s;cin>>s;
  _hash fr,rv;fr.s=s;fr.make_hash();
  rv.s=s;reverse(rv.s.begin(),rv.s.end());
  rv.make_hash();
  int n=s.size();
  for(int i=0;i<n;i++)
  {
    for(int j=n-1;j>i;j--)
    {
    }
  }
  return 0;
}