/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:20:19                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,c;cin>>a>>b>>c;
   long lft=4*a*b,rgt=(c-a-b)*(c-a-b);
  if(lft<rgt)cout<<"Yes\n";
  else cout<<"No\n";
   return 0;
}