/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 18:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101550/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double n,r;cin>>n>>r;
  cout<<setprecision(10)<<fixed;
  double now=r/(n+1);double ans=now;
   for(int i=2;i<=N;i++)
  {
    now*=((n+i-r)/(n+i));
    ans=max(ans,i*now);
  }
  cout<<ans<<endl;
  return 0;
}