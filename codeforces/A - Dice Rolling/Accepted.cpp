/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1093/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int x;cin>>x;
    int cnt=0;
    while(true)
    {
      cnt++;
      if(x>=2&&x<=7)break;
      x-=2;
    }
    cout<<cnt<<endl;
  }
  return 0;
}