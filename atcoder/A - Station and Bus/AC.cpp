/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 23:19:55                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc158/tasks/abc158_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a;cin>>a;int f=0,g=0;
  if(a[0]=='A')f=1;
  if(a[1]=='A')f=1;
  if(a[2]=='A')f=1;
   if(a[0]=='B')g=1;
  if(a[1]=='B')g=1;
  if(a[2]=='B')g=1;
   if(f&g)cout<<"Yes\n";else cout<<"No\n";
    return 0;
}