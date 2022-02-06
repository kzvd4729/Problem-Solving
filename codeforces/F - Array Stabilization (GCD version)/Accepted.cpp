/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2021 23:03                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 218 ms                                          memory_used: 40200 KB                             
*  problem: https://codeforces.com/contest/1547/problem/F
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
 const int N=4e5,inf=1e9;
 int a[N+2];
 int sp[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=a[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=__gcd(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return __gcd(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[n+i]=a[i];
     build(n+n);
     int lo=0,hi=n-1,md,ans;
    while(lo<=hi)
    {
      md=(lo+hi)/2;
       int gc=get(1,1+md),f=0;
      for(int i=2;i<=n;i++)if(get(i,i+md)!=gc)f=1;
       if(f)lo=md+1;
      else ans=md,hi=md-1;
    }
    cout<<ans<<endl;
  }
     return 0;
}