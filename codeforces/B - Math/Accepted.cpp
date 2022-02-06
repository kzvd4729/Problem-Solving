/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2018 22:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1062/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mx,pw[N+2],tw,ok;set<int>st;
int upd(int x)
{
  for(int i=0;i<=26;i++)
  {
    if(x<=pw[i])
    {
      return i;
    }
  }
}
int factorise(int n)
{
  int ret=1;
  for(int i=2;i<=n;i++)
  {
    if(n==1)break;
    if(n%i==0)
    {
      int cnt=0;
      while(n%i==0)
      {
        cnt++;n/=i;
      }
      ret*=i;
      st.insert(cnt);
      mx=max(mx,upd(cnt));
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;for(int i=1;i<=26;i++)pw[i]=pw[i-1]*2;
  int n;cin>>n;
   if(n==1)cout<<1<<" "<<0<<endl,exit(0);
   int nn=factorise(n);
   if(st.size()==1)
  {
    int x=*st.begin();
    if(__builtin_popcount(x)==1)
      ok=1;
  }
  if(ok)cout<<nn<<" "<<mx<<endl;
  else cout<<nn<<" "<<mx+1<<endl;
   return 0;
}