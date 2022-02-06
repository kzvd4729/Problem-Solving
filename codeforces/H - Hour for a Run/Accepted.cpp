/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/04/2019 23:40                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102346/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   int tt=n*k;
   for(int i=1;i<=9;i++)
  {
    int ans=(tt*i+9)/10;
    cout<<ans<<" ";
  }
  cout<<endl;
   return 0;
}