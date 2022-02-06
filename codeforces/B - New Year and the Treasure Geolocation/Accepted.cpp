/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 13:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1091/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mn1=1e9,mn2=1e9;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    mn1=min(mn1,x);mn2=min(mn2,y);
  }
  int mx1=-1e9,mx2=-1e9;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    mx1=max(mx1,x);mx2=max(mx2,y);
  }
  cout<<mn1+mx1<<" "<<mn2+mx2<<endl;
  return 0;
}