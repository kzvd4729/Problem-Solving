/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 14:50:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 330                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1054
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
vector<long>fr;
vector<int>factorise(int x)
{
  fr.clear();
  int sq=sqrt(x+1);vector<int>ret;
  for(int i=2;i<=sq;i++)
  {
    if(x%i)continue;
    ret.push_back(i);int cnt=0;
    while(x%i==0)x/=i,cnt++;fr.push_back(cnt);
    if(x==1)break;
  }
  if(x!=1)ret.push_back(x),fr.push_back(1);
  return ret;
}
int big(int b,long p,int m=mod)
{
  int ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b)%m;
    b=(1LL*b*b)%m;p/=2;
  }
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    vector<int>v=factorise(n);
    for(auto &x:fr)
    {
      x*=m;//cout<<"**"<<x<<endl;
    }
    long ans=1;int pt=0;
    for(auto x:v)
    {
      long ml=big(x-1,mod-2);
      ml=(ml*(big(x,fr[pt]+1)-1))%mod;
      ans=(ans*ml)%mod;pt++;
    }
    cout<<"Case "<<++tc<<": "<<(ans+mod)%mod<<"\n";
  }
  return 0;
}