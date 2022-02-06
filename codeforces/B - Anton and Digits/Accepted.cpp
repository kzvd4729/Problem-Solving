/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 22:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/734/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long sum;
int main()
{
  ios_base::sync_with_stdio(0);
   int a,b,c,d;cin>>a>>b>>c>>d;
  while(a&&c&&d)
  {
    sum+=256;
    a--,c--,d--;
  }
  while(a&&b)
  {
    sum+=32;
    a--,b--;
  }
  cout<<sum<<endl;
  return 0;
}