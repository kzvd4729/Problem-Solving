/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 17:10:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 220                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11526
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;int sq=sqrt(n*1.0+0.0001);
    long ans=0;
    for(long i=1;i<=sq;i++)
    {
      long rt=n/i;ans+=rt;
      long lt=max((long)(n/(i+1))+1,i+1);
      if(lt<=rt)ans+=(rt-lt+1)*i;
    }
    cout<<ans<<"\n";
  }
  return 0;
}