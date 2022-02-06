/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2019 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3494 ms                                         memory_used: 132100 KB                            
*  problem: https://codeforces.com/contest/785/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>ordered_set;
const int N=2e5;
ordered_set pre[N+2],suf[N+2];
int aa[N+2];
void pre_upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    pre[x].insert(vl);
}
void pre_del(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    pre[x].erase(vl);
}
int pre_get(int x,int vl)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=pre[x].size()-pre[x].order_of_key(vl);
  return ret;
}
void suf_upd(int x,int vl)
{
  for( ;x>0;x-=x&-x)
    suf[x].insert(vl);
}
void suf_del(int x,int vl)
{
  for( ;x>0;x-=x&-x)
    suf[x].erase(vl);
}
int suf_get(int x,int vl)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)
    ret+=suf[x].order_of_key(vl);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    aa[i]=i;
    pre_upd(i,i);suf_upd(i,i);
  }
  long ans=0;
  while(q--)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    ans-=pre_get(v-1,aa[v]);ans-=suf_get(v+1,aa[v]);
    pre_del(v,aa[v]);suf_del(v,aa[v]);
    ans-=pre_get(u-1,aa[u]);ans-=suf_get(u+1,aa[u]);
    pre_del(u,aa[u]);suf_del(u,aa[u]);
     ans+=pre_get(v-1,aa[u]);ans+=suf_get(v+1,aa[u]);
    pre_upd(v,aa[u]);suf_upd(v,aa[u]);
    ans+=pre_get(u-1,aa[v]);ans+=suf_get(u+1,aa[v]);
    pre_upd(u,aa[v]);suf_upd(u,aa[v]);
    swap(aa[v],aa[u]);
     cout<<ans<<"\n";
  }
  return 0;
}