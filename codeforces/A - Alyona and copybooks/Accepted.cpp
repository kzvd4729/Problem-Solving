/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2018 16:56                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/740/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,c;
map<long,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b>>c;
   mp[n-1]=1e12;
  mp[n-2]=1e12;
  mp[n-3]=1e12;
  mp[n]=0;
  mp[n+1]=a;
  mp[n+2]=b;
  mp[n+3]=c;
    for(long i=n+1;i<=n+100;i++)
  {
    mp[i]=mp[i-1]+a;
    mp[i]=min(mp[i],mp[i-2]+b);
    mp[i]=min(mp[i],mp[i-3]+c);
  }
  long mx=1e12;
   for(long i=n;i<=n+100;i++)
  {
    if(i%4==0)
      mx=min(mx,mp[i]);
  }
  cout<<mx<<endl;
  return 0;
}