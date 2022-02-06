/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2020 19:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1231 ms                                         memory_used: 25000 KB                             
*  problem: https://codeforces.com/contest/1220/problem/F
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
const int N=2e5;
int b[N+N+2],a[N+2],po[N+2];
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
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int dfs(int lo,int hi)
{
  if(lo>hi)return 0;
  int id=po[get(lo,hi)];
   return 1+max(dfs(lo,id-1),dfs(id+1,hi));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>b[i],b[n+i]=b[i];
    if(b[i]==1)p=i;
  }
  int lo=1,hi=n,md;
  while(hi-lo>10)
  {
    md=(lo+hi)/2;int id=md;
    for(int i=p;i<p+n;i++)
    {
      if(id==n+1)id=1;
      a[id++]=b[i];
    }
    for(int i=1;i<=n;i++)po[a[i]]=i;
    build(n);
     id=po[get(1,n)];
    int lft=dfs(1,id-1),rgt=dfs(id+1,n);
    if(lft<rgt)lo=md;else hi=md;
  }
  int ans=1e9,q;
  for(md=lo;md<=hi;md++)
  {
    int id=md;
    for(int i=p;i<p+n;i++)
    {
      if(id==n+1)id=1;
      a[id++]=b[i];
    }
    for(int i=1;i<=n;i++)po[a[i]]=i;
    build(n);
     id=po[get(1,n)];
    int now=1+max(dfs(1,id-1),dfs(id+1,n));
    if(now<ans)ans=now,q=md;
  }
  int nx;if(q<=p)nx=p-q;else nx=p+n-q;
  cout<<ans<<" "<<nx<<endl;
  return 0;
}