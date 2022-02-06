/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2019 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1136/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   int mn=min(k-1+n-1,n-k+n-1);
  cout<<mn+n+1+n<<endl;
    return 0;
}