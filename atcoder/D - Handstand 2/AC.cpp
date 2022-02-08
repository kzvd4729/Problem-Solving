/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 18:10:39                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 7 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc152/tasks/abc152_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
int mt[12][12];
int dgt(int x)
{
  int dg=0;
  while(x)
  {
    x/=10;dg++;
  }
  return dg;
}
int msb(int x)
{
  int dg=dgt(x);
  int ml=1;
  for(int i=1;i<dg;i++)ml*=10;
  return x/ml;
}
int pw(int x)
{
  int ml=1;
  for(int i=1;i<=x;i++)ml*=9;
  return ml;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   for(int i=1;i<=n;i++)
  {
    int a=msb(i),b=i%10;
    mt[a][b]++;
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int a=msb(i),b=i%10;
    if(a&&b)ans+=mt[b][a];
  }
  cout<<ans<<endl;
  return 0;
}