/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 19:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/735/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,a,b;cin>>n>>a>>b;if(a>b)swap(a,b);
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1,greater<int>());
   double sum=0,ans=0;
  for(int i=1;i<=a;i++)sum+=aa[i]*1.0;
   ans+=sum/(a*1.0);
   sum=0;
  for(int i=a+1;i<=a+b;i++)sum+=aa[i]*1.0;
  ans+=sum/(b*1.0);
   cout<<setprecision(10)<<fixed<<ans<<endl;
   return 0;
}