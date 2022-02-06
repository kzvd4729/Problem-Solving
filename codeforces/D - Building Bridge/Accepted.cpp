/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/06/2020 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/250/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int lt[N+2],rt[N+2],cs[N+2],a,b;
double ds(int i,int j)
{
  return sqrt(1.0*(a-b)*(a-b)+1.0*(lt[i]-rt[j])*(lt[i]-rt[j]));
}
double sq(int i)
{
  return sqrt(1.0*a*a+1.0*lt[i]*lt[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m>>a>>b;
  for(int i=1;i<=n;i++)cin>>lt[i];
  for(int i=1;i<=m;i++)cin>>rt[i];
  for(int i=1;i<=m;i++)cin>>cs[i];
   double ans=1e18,p1,p2;
  for(int i=1;i<=m;i++)
  {
    int lo=1,hi=n,md1,md2;
    while(hi-lo>6)
    {
      md1=(lo+lo+hi)/3;md2=(lo+hi+hi)/3;
      double d1=ds(md1,i)+sq(md1),d2=ds(md2,i)+sq(md2);
       if(d1<d2)hi=md2;else lo=md1;
    }
    for(int md=lo;md<=hi;md++)
    {
      double d=ds(md,i)+sq(md)+cs[i];
      if(d<ans)ans=d,p1=md,p2=i;
    }
  }
  cout<<p1<<" "<<p2<<endl;
  return 0;
}