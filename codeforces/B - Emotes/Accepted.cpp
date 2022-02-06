/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2019 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1117/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
  long a=aa[n],b=aa[n-1];
  long c=m/(k+1);
  long ans=(b*c)+(a*(m-c));
  cout<<ans<<endl;
   return 0;
}