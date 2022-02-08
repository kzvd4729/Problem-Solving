/****************************************************************************************
*  @author: kzvd4729                                         created: 07-09-2018 19:01:42                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/SEPT18A/problems/BSHUFFLE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cout<<i<<" ";
  cout<<endl;
  for(int i=n;i>=1;i--)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}