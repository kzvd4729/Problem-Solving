/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-27 21:42:13                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/URAL-1090
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct treap
{
  int l,r,vl,prio,sz;
}tr[N+2];
void _sz(int node)
{
  if(!node)return ;
  tr[node].sz=tr[tr[node].l].sz+tr[tr[node].r].sz+1;
}
pair<int,int>split_vl(int node,int vl)
{
  if(!node)return {0,0};
  if(tr[node].vl<=vl)
  {
    pair<int,int>ret=split_vl(tr[node].r,vl);
    tr[node].r=ret.first;_sz(node);
    return {node,ret.second};
  }
  else
  {
    pair<int,int>ret=split_vl(tr[node].l,vl);
    tr[node].l=ret.second;_sz(node);
    return {ret.first,node};
  }
}
pair<int,int>split_sz(int node,int ss)
{
  if(!node)return {0,0};
  if(tr[tr[node].l].sz>=ss)
  {
    pair<int,int>ret=split_sz(tr[node].l,ss);
    tr[node].l=ret.second;_sz(node);
    return {ret.first,node};
  }
  else
  {
    pair<int,int>ret=split_sz(tr[node].r,ss-tr[tr[node].l].sz-1);
    tr[node].r=ret.first;_sz(node);
    return {node,ret.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(tr[lt].prio>=tr[rt].prio)
  {
    tr[lt].r=join(tr[lt].r,rt);_sz(lt);
    return lt;
  }
  else
  {
    tr[rt].l=join(lt,tr[rt].l);_sz(rt);
    return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int mx=-1,ans;
  for(int i=1;i<=k;i++)
  {
    int sum=0;int nw=0,root=0;
    for(int j=1;j<=n;j++)
    {
      int x;cin>>x;

      pair<int,int>p=split_vl(root,x-1);
      sum+=j-tr[p.first].sz-1;
      ++nw;tr[nw]={0,0,x,rand(),1};
      root=join(p.first,p.second);
      root=join(root,nw);
    }
    if(sum>mx)mx=sum,ans=i;
  }
  cout<<ans<<endl;
  return 0;
}