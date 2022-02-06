/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2019 12:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102428/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int ans=0;
  for(int i=1;i<=n;i++)
  {
   int j;
   for(j=i+1;j<=n;j++)
    if(aa[j]-aa[j-1]>k)break;
   ans=max(ans,j-i);
  }
  cout<<ans<<endl;
    return 0;
}