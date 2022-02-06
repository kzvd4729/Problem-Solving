/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 19:55                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/935/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e5;
int a[N+2],b[N+2],n,m,cnt;
long bigmod(long b,long p)
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
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    if(!a[i])cnt++;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];
    if(!b[i])cnt++;
  }
  long dw=bigmod(m,cnt);
  long up=0;
  long eq=0;
  long mm=((m*(m-1))/2)%mod;
  int f=0;
  for(int i=1;i<=n;i++)
  {
    if(!a[i])cnt--;
    if(!b[i])cnt--;
    long here=0;
    if(a[i]==0&&b[i]==0)
    {
      here=(mm*bigmod(m,cnt))%mod;
      here=(here*bigmod(m,eq))%mod;
      eq++;
    }
    else if(a[i]==0)
      here=((m-b[i])*bigmod(m,cnt))%mod;
    else if(b[i]==0)
      here=((a[i]-1)*bigmod(m,cnt))%mod;
    else if(a[i]>b[i])
      here=bigmod(m,cnt),f=1;
    else if(b[i]>a[i])f=1;
    up=(up+here)%mod;
    if(f)break;
  }
  cout<<(up*bigmod(dw,mod-2))%mod<<endl;
  return 0;
}