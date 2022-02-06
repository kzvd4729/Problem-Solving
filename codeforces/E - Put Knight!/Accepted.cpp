/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 15:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/120/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int W=26;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
  int t;cin>>t;
 while(t--)
  {
    int n;cin>>n;
    cout<<((n&1)^1)<<endl;
  }
   return 0;
}