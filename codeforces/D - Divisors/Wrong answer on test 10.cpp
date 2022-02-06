/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2018 16:11                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1033/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const long N=5e2;
map<long,long>mp1,mp2;
long aa[N+2];
vector<long>pr;
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
  long lo=0,hi=1500000LL,md;
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
      mp1[fr]+=2,pr.push_back(fr);
    else if(prime(sc)&&(sc*sc*sc*sc)==x)
      mp1[sc]+=4,pr.push_back(sc);
    else if(prime(th)&&(th*th*th)==x)
      mp1[th]+=3,pr.push_back(th);
    else
    {
      long f=0;long str=-1;
      for(long j=1;j<i;j++)
      {
        long gcd=__gcd(x,aa[j]);
        if(gcd!=1&&gcd!=x)
        {
          if(mp2[aa[j]])
          {
            mp1[gcd]+=mp2[aa[j]];
            mp1[aa[j]/gcd]+=mp2[aa[j]];
            mp2[aa[j]]=0;
          }
          str=gcd;
        }
      }
      if(str!=-1)mp1[str]++,mp1[x/str]++;
      else mp2[x]++;
    }
  }
  long ans=1;
  for(auto x:mp2)
  {
    if(!x.second)continue;
    for(auto z:pr)
    {
      if(x.first%z==0)
      {
        mp1[z]+=x.second;
        mp1[x.first/z]+=x.second;
        x.second=0;
      }
    }
    if(x.second)ans*=(x.second+1)*(x.second+1);
  }
  for(auto x:mp1)
    ans*=(x.second+1);
  cout<<ans<<endl;cout.flush();
   return 0;
}