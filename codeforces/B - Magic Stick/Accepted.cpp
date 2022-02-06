/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2019 22:42                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1257/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x,y;cin>>x>>y;
    if(x==3&&y>3)cout<<"NO\n";
    else if(x==2&&y>3)cout<<"NO\n";
    else if(x==1&&y>1)cout<<"NO\n";
    else cout<<"YES\n";
  }
   return 0;
}