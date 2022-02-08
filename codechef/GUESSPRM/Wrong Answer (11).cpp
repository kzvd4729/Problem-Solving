/****************************************************************************************
*  @author: kzvd4729                                         created: 14-07-2019 13:28:26                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/JULY19A/problems/GUESSPRM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long vis[N+2];
vector<long>prime;
void seive(void)
{
  for(long i=2;i<=N;i++)
  {
    if(vis[i])continue;
    prime.push_back(i);
    for(long j=i+i;j<=N;j+=i)
      vis[j]=1;
  }
}
vector<long>fac(long a,long r)
{
  vector<long>v;
  for(auto x:prime)
  {
    if(a%x)continue;
    if(x>r)v.push_back(x);
    while(a%x==0)a/=x;
  }
  if(a!=1&&a>r)v.push_back(a);
  return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();long t;cin>>t;
  while(t--)
  {
    long x1=(1LL<<16LL);
    cout<<1<<" "<<x1<<endl;
    long r;cin>>r;
    if(r==0)
    {
      cout<<2<<" "<<2<<endl;
      string s;cin>>s;
      continue;
    }
    vector<long>v=fac(x1*x1-r,r);
    sort(v.begin(),v.end());
    long x2=v.back();
    while(true)
    {
      if(x2*v.back()<=1000000000)x2*=v.back();
      else break;
    }
    cout<<1<<" "<<x2<<endl;
    cin>>r;
    if(r==0)
    {
      cout<<2<<" "<<v.back()<<endl;
      string s;cin>>s;
      continue;
    }
    long nm=x2*x2-r;
    for(auto x:v)
    {
      if(x<=r||nm%x)continue;
      cout<<2<<" "<<x<<endl;
      string s;cin>>s;
      break;
    }
  }
  return 0;
}