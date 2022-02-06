/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 20:10                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/977/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  while(k--)
  {
    if(n%10==0)
      n/=10;
    else n--;
  }
  cout<<n<<endl;
  return 0;
}