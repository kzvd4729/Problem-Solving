/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 21:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1305/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long fr[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
  {
    //aa[i]=rand();
    cin>>aa[i];//aa[i]%=m;
    //fr[aa[i]]++;
  }
  sort(aa+1,aa+n+1);
  long ans=1;
  for(long i=1;i<=n;i++)
  {
    long md=aa[i]%m;
    for(long j=0;j<m;j++)
    {
      if(fr[j])
      {
        ans=(ans*(md-j)*fr[j])%m;
      }
    }
    if(ans==0)break;
    fr[md]++;
  }
  cout<<(ans+m)%m<<endl;
  return 0;
}