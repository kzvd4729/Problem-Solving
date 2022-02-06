/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2018 21:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1062/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  ++n;aa[n]=1001;
  int ans=0;
  for(int i=0;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(aa[j]==aa[i]+j-i)
      {
        ans=max(ans,j-i-1);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}