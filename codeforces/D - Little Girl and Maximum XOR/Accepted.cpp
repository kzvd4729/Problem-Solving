/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 23:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/276/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long lt,rt,hi,lo;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>lt>>rt;
  for(long i=60;i>=0;i--)
  {
    if((hi|(1LL<<i))<=rt&&(lo|((1LL<<i)-1))>=lt)
      hi|=(1LL<<i);
    else if((lo|(1LL<<i))<=rt&&(hi|((1LL<<i)-1))>=lt)
      lo|=(1LL<<i);
    else if((hi|(1LL<<i))<=rt)hi|=(1LL<<i),lo|=(1LL<<i);
  }
  cout<<(hi^lo)<<endl;
  return 0;
}