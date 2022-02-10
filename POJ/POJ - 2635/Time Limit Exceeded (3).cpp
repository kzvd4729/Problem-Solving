/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-05 12:07:29                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
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
  while(cin>>s>>n)
  {
    if(!n)break;int f=0;
    for(int i=1;i<=p;i++)
    {
      if(prime[i]>n)break;
      int mod=0;
      for(int j=0;j<s.size();j++)
        mod=(mod*10+s[j]-'0')%prime[i];
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