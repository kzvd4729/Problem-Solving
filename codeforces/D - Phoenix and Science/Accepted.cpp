/****************************************************************************************
*  @author: * kzvd4729                                       created: May/01/2020 22:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1348/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const long N=1e6,mod=1e9+7;
long pw[N+2],ans[N+2],ln;
void dec(long id)
{
  ans[id]--;long av=1;
  for(long i=1;i<=id;i++)
    av=(av-ans[i])+ans[i]+ans[i];
  for(long i=id+1;i<=ln;i++)
  {
    ans[i]=av;av+=av;
  }
}
long cal()
{
  long sm=0,now=0;
  for(long i=0;i<=ln;i++)
  {
    now+=ans[i];sm+=now;
  }
  return sm;
}
long tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    pw[0]=1;pw[1]=1;for(long i=2;i<=30;i++)pw[i]=pw[i-1]*2;
    long n;cin>>n;long sm=0,now=0;
    for(ln=0; ;ln++)
    {
      now+=pw[ln];sm+=now;
      if(sm>=n)break;
    }
    cout<<ln<<endl;
    for(long i=0;i<=ln;i++)ans[i]=pw[i];
    //for(long i=1;i<=ln;i++)cout<<ans[i]<<" ";cout<<"\n";
    for(long i=1;i<=ln;i++)
    {
      for(long j=1;j<=ln;j++)tmp[j]=ans[j];
      dec(i);//cout<<"*"<<cal()<<endl;
      if(cal()<n)for(long j=1;j<=ln;j++)ans[j]=tmp[j];
      else i--;
    }
    if(cal()!=n)assert(0);
    for(long i=1;i<=ln;i++)cout<<ans[i]<<" ";cout<<"\n";
  }
  return 0;
}