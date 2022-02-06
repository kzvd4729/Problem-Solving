/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/23/2019 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1108/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a<c)
    {
      cout<<a<<" "<<d<<endl;
    }
    else
    {
      cout<<b<<" "<<c<<endl;
    }
  }
  return 0;
}