/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1307/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=2;i<=n;i++)
    {
      int mv=min(aa[i],d/(i-1));
      aa[1]+=mv;d-=mv*(i-1);
    }
    cout<<aa[1]<<"\n";
  }
  return 0;
}