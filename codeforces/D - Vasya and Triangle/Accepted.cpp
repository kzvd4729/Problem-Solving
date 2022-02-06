/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2018 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1058/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;vector<long>vv;
  for(long i=1;i<=sqrt(n+1);i++)
  {
    if(n%i==0)
    {
      vv.push_back(i);
      vv.push_back(n/i);
    }
  }
  for(long i=1;i<=sqrt(m+1);i++)
  {
    if(m%i==0)
    {
      vv.push_back(i);
      vv.push_back(m/i);
    }
  }
  long z=n*m*2LL;
  if((z%k)!=0)cout<<"NO"<<endl,exit(0);
  z/=k;
  for(auto x:vv)
  {
    if(z%x==0)
    {
      long a=x,b=z/x;
      if(a<=n&&b<=m)
      {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<"0 "<<b<<endl;
        cout<<a<<" 0"<<endl;
        exit(0);
      }
      if(a<=m&&b<=n)
      {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<"0 "<<a<<endl;
        cout<<b<<" 0"<<endl;
        exit(0);
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}