/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 18:09:46                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 17 ms                                           memory_used: 5888 KB                              
*  problem: https://atcoder.jp/contests/abc154/tasks/abc154_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
double aa[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    aa[i]=(1.0*((x*(x+1))/2))/(1.0*x);
    qm[i]=qm[i-1]+aa[i];
  }
  double mx=0;
  for(int i=k;i<=n;i++)
    mx=max(mx,qm[i]-qm[i-k]);
  cout<<setprecision(10)<<fixed<<mx<<endl;
   return 0;
}