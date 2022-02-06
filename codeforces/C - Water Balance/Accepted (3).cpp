/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 15:10                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1637 ms                                         memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/1299/problem/C
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
double a[N+2];int sz[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)scanf("%lf",&a[i]),sz[i]=1;
  for(int i=n;i>=1;i--)
  {
    for(int j=i+1;j<=n;j+=sz[j])
    {
      if(a[j]>a[i])break;
      a[i]=(a[i]*sz[i]+a[j]*sz[j])/((sz[i]+sz[j])*1.0);
      sz[i]+=sz[j];
    }
  }
  for(int i=1;i<=n;i+=sz[i])
  {
    for(int j=1;j<=sz[i];j++)
    {
      printf("%.10lf\n",a[i]);
    }
  }
  return 0;
}