/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 17:05:08                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
double aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;double sum=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i];
  }
  double avg=sum/(n*1.0);
   double mx=1e9;int ans;
  for(int i=1;i<=n;i++)
  {
    double df=abs(avg-aa[i]);
    if(df<mx)
    {
      mx=df;ans=i;
    }
  }
  cout<<ans-1<<endl;
  return 0;
}