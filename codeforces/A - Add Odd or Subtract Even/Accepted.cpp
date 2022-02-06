/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 15:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1311/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    int x=abs(a-b);
    if(x==0)
    {
      cout<<0<<endl;
    }
    else if(a>b)
    {
      if(x%2)cout<<2<<endl;
      else cout<<1<<endl;
    }
    else
    {
      if(x%2)cout<<1<<endl;
      else cout<<2<<endl;
    }
  }
  return 0;
}