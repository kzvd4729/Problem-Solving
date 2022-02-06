/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2020 16:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1559 ms                                         memory_used: 172800 KB                            
*  problem: https://codeforces.com/contest/1288/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
const int N=3e5,inf=1e9;
int sz;
struct segment
{
  int l,r,sm;
}seg[42*N+2];//2*lg(mx)*N
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  if(lo>rt||hi<lt)return 0;
  int md=(lo+hi)/2;
  return get(seg[node].l,lo,md,lt,rt)+get(seg[node].r,md+1,hi,lt,rt);
}
int last[N+2],root[N+2],aa[N+2],mn[N+2],mx[N+2],vis[N+2];
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)mn[i]=i,mx[i]=i;
  for(int i=1;i<=m;i++)
  {
    cin>>aa[i];mn[aa[i]]=1;int x=aa[i];
    int tmp=++sz;
    upd(tmp,1,m,root[i-1],i,1);
    if(last[x]){root[i]=++sz;upd(root[i],1,m,tmp,last[x],-1);}
    else root[i]=tmp;
     last[x]=i;
  }
  Ordered_Set st;
  for(int i=1;i<=m;i++)
  {
    if(vis[aa[i]]==0)
    {
      int big=st.size()-st.order_of_key(aa[i]+1);
      vis[aa[i]]=1;if(big>0)mx[aa[i]]+=big;
    }
    st.insert(aa[i]);
    pos[aa[i]].push_back(i);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==0)
    {
      int big=st.size()-st.order_of_key(i+1);
      vis[i]=1;if(big>0)mx[i]+=big;
    }
  }
  for(int i=1;i<=n;i++)
  {
    pos[i].push_back(m+1);
    //cout<<i<<endl;
    for(int j=0;j<pos[i].size()-1;j++)
    {
      int lt=pos[i][j]+1,rt=pos[i][j+1]-1;
      if(rt>=lt)mx[i]=max(mx[i],1+get(root[rt],1,m,lt,rt));
      //cout<<lt<<" "<<rt<<" "<<get(root[rt],1,m,lt,rt)<<endl;
    }
  }
  for(int i=1;i<=n;i++)cout<<mn[i]<<" "<<mx[i]<<endl;
  return 0;
}