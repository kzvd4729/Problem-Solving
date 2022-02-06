/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/967/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,s,x,y,t[100005],now;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  for(int i=1;i<=n;i++)
  {
    cin>>x>>y;
    t[i]=x*60+y;
  }
  t[n+1]=1e9;
  now=0;
  for(int i=1;i<=n+1;i++)
  {
    if(t[i]-now-1>=s)
    {
      cout<<now/60<<" "<<now%60<<endl;
      return 0;
    }
    now=t[i]+s+1;
  }
  return 0;
}