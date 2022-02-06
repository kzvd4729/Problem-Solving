/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 20:01                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++11                               
*  run_time: 280 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/716/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
long n,now;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  now=2;
  cout<<2<<endl;
  for(long i=2;i<=n;i++)
  {
    long tmp=i*(i+1);
    tmp=tmp*tmp;
    cout<<(tmp-now)/i<<endl;
    now=sqrt(tmp);
  }
  return 0;
}