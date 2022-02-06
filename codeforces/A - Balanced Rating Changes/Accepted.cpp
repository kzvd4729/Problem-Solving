/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2019 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1237/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int ev=0,od=0,bl=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(abs(x)%2==0)
    {
      cout<<x/2<<"\n";
    }
    else if(x>0)
    {
      if(ev)cout<<x/2<<"\n";
      else cout<<(x+1)/2<<"\n";
      ev^=1;
    }
    else
    {
      x=abs(x);
      if(od)cout<<-(x/2)<<"\n";
      else cout<<-((x+1)/2)<<"\n";
      od^=1;
    }
  }
  return 0;
}