/****************************************************************************************
*  @author: kzvd4729                                         created: 03-11-2018 00:44:03                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/NOV18A/problems/PRITREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
    cout<<i<<" "<<i+1<<endl;
  return 0;
}