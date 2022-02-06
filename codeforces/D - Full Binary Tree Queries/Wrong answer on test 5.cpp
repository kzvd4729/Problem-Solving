/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2018 21:19                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/960/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int q;
long x,k,lv,lev[102],pw[102],ty;
void print(long now)
{
  lv=64-__builtin_clzll(x);
  long pr=now;
  now+=lev[lv];
  if(now>pw[lv])now=pw[lv-1]+now-pw[lv];
  for(int i=lv;i>=1;i--)
  {
    cout<<pr<<" ";
    now/=2;
    pr=now-lev[i-1];
    if(pr<pw[i-2])pr=pw[i-1]-(pw[i-2]-pr);
  }
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(int i=1;i<=60;i++)pw[i]=pw[i-1]*2LL;
   cin>>q;
  while(q--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>x>>k;
      lv=64-__builtin_clzll(x);
      if(k<0)k+=pw[lv];
      lev[lv]+=k;
      lev[lv]%=pw[lv-1];
    }
    else if(ty==2)
    {
      cin>>x>>k;
      lv=64-__builtin_clzll(x);
      if(k<0)k+=pw[lv];
      for(int i=lv;i<=60;i++)
      {
        k%=pw[i-1];
        lev[i]+=k;
        lev[i]%=pw[i-1];
        k*=2LL;
      }
    }
    else
    {
      cin>>x;
      print(x);
    }
  }
  return 0;
}