/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 17:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1481 ms                                         memory_used: 203400 KB                            
*  problem: https://codeforces.com/contest/1312/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,sz,vis[N+2],ans[N+2];
int seg[5*N+2],lz[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  if(!lz[node])return ;int md=(lo+hi)/2;
  if(lo==hi)seg[node]=min(seg[node],lz[node]);
  else
  {
    if(lz[node*2]==0)lz[node*2]=1e9;
    if(lz[node*2+1]==0)lz[node*2+1]=1e9;
     lz[node*2]=min(lz[node*2],lz[node]);
    lz[node*2+1]=min(lz[node*2+1],lz[node]+md-lo+1);
  }
  lz[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]=vl+lo-lt;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
}
int get(int node,int lo,int hi,int id)
{
  tooLazy(node,lo,hi);
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  if(id<=md)return get(node*2,lo,md,id);
  else return get(node*2+1,md+1,hi,id);
}
struct trie
{
  int nx[26];
}tr[N+2];
int tim,ent[N+2],ext[N+2];
void dfs(int now)
{
  if(vis[now])
  {
    ++tim;upd(1,1,n,tim,tim,tim);
  }
  ent[now]=tim+1;
  for(int i=0;i<26;i++)
  {
    if(tr[now].nx[i])dfs(tr[now].nx[i]);
  }
  ext[now]=tim;
}
void dfs(int now,int h)
{
  int f=0;
  if(vis[now])
  {
    h=min(h,get(1,1,n,ent[now]-1));
    ans[vis[now]]=h;f=1;
  }
  if(ent[now]<=ext[now])
  {
    //cout<<ent[now]<<" "<<ext[now]<<" "<<h+f+1<<endl;
    upd(1,1,n,ent[now],ext[now],h+f+1);
  }
    for(int i=0;i<26;i++)
  {
    if(tr[now].nx[i])dfs(tr[now].nx[i],h+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int id;char c;cin>>id>>c;
    tr[id].nx[c-'a']=++sz;
  }
  for(int i=0;i<5*N+2;i++)seg[i]=1e9;
  int k;cin>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;vis[x]=i;
  }
  dfs(0);dfs(0,0);
  // for(int i=0;i<=n;i++)
  //   cout<<i<<" "<<ent[i]<<" --> "<<ext[i]<<endl;
  for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
    cout<<endl;
     return 0;
}