/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/22/2019 21:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1249/problem/C2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long pw[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=qm[0]=1;
  for(int i=1;i<=38;i++)
  {
    pw[i]=pw[i-1]*3LL;
    qm[i]=qm[i-1]+pw[i];
  }
  int q;cin>>q;
  while(q--)
  {
    long n;cin>>n;long ans=0;
    while(ans<n)
    {
      for(int i=0;i<=38;i++)
      {
        if(ans+qm[i]>=n){ans+=pw[i];break;}
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}