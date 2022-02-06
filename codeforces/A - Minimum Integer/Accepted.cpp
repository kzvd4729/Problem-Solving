/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1101/problem/A
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
    int lt,rt,d;cin>>lt>>rt>>d;
     if(d<lt)
    {
      cout<<d<<endl;
      continue;
    }
    long dv=rt/d;
    dv=(dv+1)*d;
    cout<<dv<<endl;
  }
  return 0;
}