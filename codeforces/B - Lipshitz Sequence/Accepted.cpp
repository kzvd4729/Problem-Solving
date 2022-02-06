/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2020 16:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 18600 KB                             
*  problem: https://codeforces.com/contest/601/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
int sp[N+2][20+2],id[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=aa[i],id[i][0]=i;//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];id[i][j]=id[i][j-1];
      if((i+(1<<(j-1)))<=n)
      {
        if(sp[i+(1<<(j-1))][j-1]>sp[i][j])
          sp[i][j]=sp[i+(1<<(j-1))][j-1],id[i][j]=id[i+(1<<(j-1))][j-1];
      }
    }
  }
}
pair<int,int>get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  if(sp[lt][dg]>sp[rt-(1<<dg)+1][dg])return {sp[lt][dg],id[lt][dg]};
  return {sp[rt-(1<<dg)+1][dg],id[rt-(1<<dg)+1][dg]};
}
int bb[N+2];long ans;
void dfs(int l,int r)
{
  if(l==r)return ;
  pair<int,int>p=get(l+1,r);ans+=1LL*p.first*(p.second-l)*(r-p.second+1);
  dfs(l,p.second-1);dfs(p.second,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>bb[i];
  for(int i=1;i<=n;i++)aa[i]=abs(bb[i]-bb[i-1]);
  build(n);
  while(q--)
  {
    int u,v;cin>>u>>v;ans=0;
    dfs(u,v);cout<<ans<<"\n";
  }
  return 0;
}