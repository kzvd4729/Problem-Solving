/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 18:02:01                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc154/tasks/abc154_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string c,d,e;cin>>c>>d;
  int a,b;cin>>a>>b>>e;
   if(e==c)a--;else b--;
  cout<<a<<" "<<b<<endl;
    return 0;
}