/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101972/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,x,y;cin>>n>>x>>y;
    int a=(n+1)/2,b=n/2;
    if(x>=a&&y>=b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}