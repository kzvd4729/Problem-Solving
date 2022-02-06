/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2020 12:30                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 12900 KB                             
*  problem: https://codeforces.com/contest/280/problem/B
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
const int N=1e5;
int sp[N+2][20+2],a[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=a[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  if(rt<lt)return -1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  build(n);int ans=0;

  for(int i=1;i<=n;i++)
  {
    int lo=i+1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(i+1,md)>a[i])hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)if(get(i+1,md)>a[i])break;
    if(md<=n)ans=max(ans,a[i]^a[md]);

    lo=1,hi=i-1,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(md,i-1)>a[i])lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)if(get(md,i-1)>a[i])break;
    if(md)ans=max(ans,a[i]^a[md]);
  }
  cout<<ans<<endl;
  return 0;
}