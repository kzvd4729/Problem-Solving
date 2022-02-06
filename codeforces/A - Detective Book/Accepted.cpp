/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1140/problem/A
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
  for(int i=1;i<=n;i++)cin>>aa[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    int nx=aa[i];ans++;
    for(int j=i; ;j++)
    {
      nx=max(nx,aa[j]);
      if(nx==j)
      {
        i=j;break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}