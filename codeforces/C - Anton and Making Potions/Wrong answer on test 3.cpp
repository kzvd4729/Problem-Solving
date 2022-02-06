/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/04/2020 11:13                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/734/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],c[N+2],d[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  int x,s;cin>>x>>s;
   for(int i=1;i<=m;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>b[i];
  for(int i=1;i<=k;i++)cin>>c[i];
  for(int i=1;i<=k;i++)cin>>d[i];
   long ans=1LL*x*n;
  for(int i=1;i<=m;i++)
  {
    int id=upper_bound(d+1,d+k+1,s-b[i])-d;
    id--;if(id==0)continue;
    int rm=max(0,n-c[id]);
    ans=min(ans,1LL*rm*a[i]);
  }
  for(int i=1;i<=k;i++)
    if(d[i]<=s)ans=min(ans,1LL*x*(n-c[i]));
  cout<<ans<<endl;
  return 0;
}