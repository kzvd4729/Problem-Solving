/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2018 17:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1033/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e2;
const long mod=998244353;
map<long,long>mp1,mp2;
long aa[N+2];
vector<long>pr,nn;
bool prime(long x)
{
  if(x==1)return false;
  long lm=sqrt(x+1);
  for(long i=2;i<=lm;i++)
    if(x%i==0)return false;
  return true;
}
long pow3(long x)
{
  long lo=0,hi=2000000LL,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(md*md*md<x)lo=md;
    else hi=md;
  }
  for(md=lo;md<=hi;md++)
  {
    if(md*md*md>=x)return md;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;aa[i]=x;
    long fr=sqrt(x+1);
    long sc=sqrt(fr+1);
    long th=pow3(x);
    if(prime(fr)&&(fr*fr)==x)
    {
      pr.push_back(fr);
      pr.push_back(fr);
    }
    else if(prime(sc)&&(sc*sc*sc*sc)==x)
    {
      pr.push_back(sc);
      pr.push_back(sc);
      pr.push_back(sc);
      pr.push_back(sc);
    }
    else if(prime(th)&&(th*th*th)==x)
    {
      pr.push_back(th);
      pr.push_back(th);
      pr.push_back(th);
    }
    else
    {
      nn.push_back(x);
    }
  }
  for(int i=0;i<nn.size();i++)
  {
    for(auto z:pr)
    {
      if(nn[i]%z==0)
      {
        pr.push_back(z);
        pr.push_back(nn[i]/z);
        nn[i]=1;
      }
    }
    for(int j=i+1;j<nn.size();j++)
    {
      long gcd=__gcd(nn[i],nn[j]);
      if(gcd!=1&&gcd!=nn[i]&&gcd!=nn[j])
      {
        pr.push_back(gcd);
        pr.push_back(gcd);
        pr.push_back(nn[i]/gcd);
        pr.push_back(nn[j]/gcd);
        nn[i]=1;nn[j]=1;
      }
    }
  }
  for(auto x:pr)mp1[x]++;
  for(auto x:nn)if(x>1)mp2[x]++;
  long ans=1;
  for(auto x:mp1)ans=(ans*(x.second+1))%mod;
  for(auto x:mp2)ans=(ans*((x.second+1)*(x.second+1))%mod)%mod;
  cout<<ans<<endl;cout.flush();
  return 0;
}