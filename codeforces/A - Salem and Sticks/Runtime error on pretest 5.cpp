/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 18:22                        
*  solution_verdict: Runtime error on pretest 5              language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1105/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n;
int ck(int x)
{
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    int xx=abs(aa[i]-x);
    if(xx)xx--;sum+=xx;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int mn=2e9,id=0;
  for(int i=0;i<=1000;i++)
  {
    int x=ck(i);
    if(x<mn)
    {
      mn=x,id=i;
    }
  }
  if(!id)assert(0);
  cout<<id<<" "<<mn<<endl;
  return 0;
}