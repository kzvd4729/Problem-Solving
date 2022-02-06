/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2018 23:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/146/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr,sv;
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  for(int i=0;a[i];i++)
  {
    if(a[i]!=b[i])
      a[i]=='4'?fr++:sv++;
  }
  cout<<max(fr,sv)<<endl;
  return 0;
}