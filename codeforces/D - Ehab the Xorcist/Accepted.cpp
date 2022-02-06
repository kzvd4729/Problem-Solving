/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/14/2020 21:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1325/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long a,b;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b;
   if(a==0&&b==0)cout<<0<<endl,exit(0);
  if(a==b)cout<<1<<endl<<a<<endl,exit(0);
  if(a>b)cout<<-1<<endl,exit(0);
   long m=0,n=0;
  for(long i=59;i>=0;i--)
  {
    if(n+m>b)break;
    if(a&(1LL<<i))m|=(1LL<<i);
    else
    {
      if(n+m+(1LL<<i)*2LL<=b)
        m|=(1LL<<i),n|=(1LL<<i);
    }
  }
  if(n+m==b)cout<<2<<endl<<n<<" "<<m<<endl,exit(0);
   if((b-a)%2)cout<<-1<<endl,exit(0);
   cout<<3<<endl;
  cout<<(b-a)/2<<" "<<(b-a)/2<<" "<<a<<endl;
  return 0;
}