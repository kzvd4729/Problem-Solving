/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 21:10:38                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/ALKH2019/problems/DANOW
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  while(q--)
  {
    int l,r;cin>>l>>r;
    long sm=0;
    for(int i=l;i<=r;i++)
      sm+=(aa[i]*1LL)*bb[i];
    cout<<sm<<"\n";
  }
  return 0;
}