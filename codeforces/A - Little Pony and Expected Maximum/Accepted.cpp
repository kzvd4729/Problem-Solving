/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2019 19:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/453/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m,n;cin>>m>>n;double ans=0;
  for(int i=1;i<=m;i++)
  {
    double x=i*1.0;
    ans+=x*(pow(x/m,n)-pow((x-1.0)/m,n));
  }
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}