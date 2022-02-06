/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 21:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1380/problem/D
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
int a[N+2],b[N+2];
const long infL=4340410370284600380LL;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;long x,k,y;cin>>x>>k>>y;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>b[i];
   int j=1,cnt=0,mx=0;b[m+1]=-1;a[n+1]=-1,b[0]=-1;
  long ans=0;
  for(int i=1;i<=n+1;i++)
  {
    if(a[i]==b[j])
    {
      long now=infL;
      if(b[j-1]>mx||b[j]>mx)now=1LL*cnt*y;
      if(cnt>=k)now=min(now,1LL*(cnt/k)*x+1LL*(cnt%k)*y);
      if(cnt>=k)now=min(now,1LL*x+1LL*(cnt-k)*y);
       if(now==infL)cout<<-1<<endl,exit(0);
      j++;ans+=now;cnt=0;mx=0;
    }
    else cnt++,mx=max(mx,a[i]);
  }
  if(j<=m)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}