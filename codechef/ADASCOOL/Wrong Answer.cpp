/****************************************************************************************
*  @author: kzvd4729                                         created: 20-01-2019 21:48:45                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK102A/problems/ADASCOOL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    if(n%2==0&&m%2==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}