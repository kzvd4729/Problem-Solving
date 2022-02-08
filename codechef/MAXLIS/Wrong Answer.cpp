/****************************************************************************************
*  @author: kzvd4729                                         created: 10-10-2019 13:09:59                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/OCT19A/problems/MAXLIS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    if(i>1)cout<<" ";
    cout<<aa[i];
  }
  cout<<endl;
  return 0;
}