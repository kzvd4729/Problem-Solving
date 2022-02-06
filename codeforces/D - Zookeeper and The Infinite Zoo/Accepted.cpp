/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 20:55                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 78 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1491/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int u,v;cin>>u>>v;
    if(u>v)
    {
      cout<<"NO\n";continue;
    }
    int a=0,b=0,f=0;
    for(int i=0;i<30;i++)
    {
      if((u&(1<<i)))a++;
      if((v&(1<<i)))b++;
       if((v&(1<<i))&&a<b)f=1;
     }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}