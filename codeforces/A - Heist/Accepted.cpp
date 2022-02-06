/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 16:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1041/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int mx=-2e9,mn=2e9;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    mx=max(mx,x);mn=min(mn,x);
  }
  cout<<mx-mn+1-n<<endl;
  return 0;
}