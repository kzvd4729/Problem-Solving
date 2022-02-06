/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 15:53                        
*  solution_verdict: Wrong answer on test 39                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/429/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],qm[N+2],sum[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];qm[i]=qm[i-1]+aa[i];
  }
  int r=min(n,100);for(int i=1;i<=r;i++)sum[i]=1e9;
  for(int i=1;i<=r;i++)
  {
    for(int j=2;j<=n;j++)
    {
      int k=j+i-1;if(k>n)break;
      sum[i]=min(sum[i],abs(qm[k]-qm[j-1]));
    }
  }
  long ans=1e18;
  for(int i=1;i<=r;i++)
    ans=min(ans,(i*1LL*i)+(sum[i]*1LL*sum[i]));
  cout<<ans<<endl;
  return 0;
}