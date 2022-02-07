/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 22:34:17                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 50                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10484
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long n,d,fr[102];
void add(int n)
{
  for(int i=2;i<=n;i++)
  {
    while(n%i==0)n/=i,fr[i]++;
  }
  if(n>1)assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>d)
  {
    if(!(n+d))break;
    memset(fr,0,sizeof(fr));
    for(int i=2;i<=n;i++)add(i);
    for(int i=2;i<=100;i++)
    {
      while(d%i==0)d/=i,fr[i]--;
    }
    if(d>1)
    {
      cout<<0<<endl;continue;
    }
    long ans=1,f=0;
    for(int i=1;i<=100;i++)
    {
      if(fr[i]<0)f=1;
      ans*=(fr[i]+1);
    }
    if(f)ans=0;cout<<ans<<endl;
  }
  return 0;
}