/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 21:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1155/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=m;i++)
    cin>>bb[i];
  for(long i=2;i<=n;i++)
    aa[i]-=aa[1];
  long gc=0;
  for(long i=2;i<=n;i++)
    gc=__gcd(gc,aa[i]);
  for(long i=1;i<=m;i++)
  {
    if(gc%bb[i]==0)
    {
      cout<<"YES"<<endl;
      cout<<aa[1]<<" "<<i<<endl;
      exit(0);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}