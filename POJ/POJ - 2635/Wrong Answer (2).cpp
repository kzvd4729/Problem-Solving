/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-05 12:01:45                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2635
****************************************************************************************/
#include<iostream>
#define long long long
using namespace std;
const int N=1e6,bl=4;
long pw[N+2],num[N+2],sz[N+2];
bool isComposit[N+2];int prime[N/10+2],p;
void linearSieve(int n)
{
  isComposit[0]=isComposit[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(!isComposit[i])prime[++p]=i;
    for(int j=1;j<=p&&i*prime[j]<=n;j++)
    {
      isComposit[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  linearSieve(N);string s;int n;
  pw[0]=1;for(int i=1;i<=bl;i++)pw[i]=pw[i-1]*10LL;
  while(cin>>s>>n)
  {
    if(!n)break;int f=0;
    int l,r=0,id=0;
    while(r<((int)s.size()))
    {
      l=r,r=min(l+bl,(int)s.size());
      long nm=0;
      for(int i=l;i<r;i++)
        nm=nm*10LL+s[i]-'0';
      num[++id]=nm;sz[id]=r-l;
    }
    /*for(int i=1;i<=id;i++)
      cout<<num[i]<<" ";
    cout<<endl;*/
    for(int i=1;i<=p;i++)
    {
      if(prime[i]>n)break;
      long mod=0;
      for(int j=1;j<=id;j++)
        mod=(mod*(pw[sz[j]]%prime[i])+num[j])%prime[i];
      if(!mod)
      {
        cout<<"BAD "<<prime[i]<<"\n";
        f=1;break;
      }
    }
    if(!f)cout<<"GOOD\n";
  }
  return 0;
}