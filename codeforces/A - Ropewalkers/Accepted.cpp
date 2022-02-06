/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1185/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long ans=0,d;
  for(int i=1;i<=3;i++)cin>>aa[i];
  cin>>d;sort(aa+1,aa+3+1);
  if(aa[2]-aa[1]<d)ans+=d-(aa[2]-aa[1]);
  if(aa[3]-aa[2]<d)ans+=d-(aa[3]-aa[2]);
  cout<<ans<<endl;
   return 0;
}