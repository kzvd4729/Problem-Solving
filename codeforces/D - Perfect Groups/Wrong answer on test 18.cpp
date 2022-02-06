/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2020 21:22                        
*  solution_verdict: Wrong answer on test 18                 language: GNU C++17                               
*  run_time: 249 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/980/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],pr[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=i-1;j>=1;j--)
    {
      long nm=1LL*a[i]*a[j];
      if(nm<0)continue;
      long sq=sqrt(nm);if(sq*sq==nm){pr[i]=j;break;}
    }
  }
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=i;j<=n;j++)
    {
      if(pr[j]<i)cnt++;
      ans[cnt]++;
    }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}