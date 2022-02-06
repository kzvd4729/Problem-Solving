/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1036/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,k;cin>>n>>k;
  cout<<(k+n-1)/n<<endl;
   return 0;
}