/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/12/2019 18:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/gym/102215/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cal(int n,int m)
{
  return max(n,0)+2*(max(0,n-m))+max(0,n-2*m);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   long ans=0;
  while(n>0)
  {
    ans+=cal(n,m);n-=2*m;
  }
  cout<<ans-m<<endl;
  return 0;
}