/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/290/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  double foo=0,bar=0,baz=0,quz=1;
  for(int i=1;i<=n;i++)
  {
    int pur;cin>>pur;
    foo+=pur,bar++;
    if(max(foo*quz,bar*baz)==foo*quz)
    {
      baz=foo;quz=bar;
    }
  }
  double ans=baz/quz;
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}