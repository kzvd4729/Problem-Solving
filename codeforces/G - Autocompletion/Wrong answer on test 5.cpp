/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 15:30                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 164400 KB                            
*  problem: https://codeforces.com/contest/1312/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz,tim,ent[N+2],ext[N+2];
int seg[5*N+2],lz[5*N+2],n,kk[N+2],vis[N+2],ans[N+2];
struct trie
{
  int nx[26],f;
}tr[N+2];
void tooLazy(int node,int lo,int hi)
{
  if(lo==hi)
  {
    if(lz[node]<0)seg[node]+=lz[node];
  }
  else lz[node*2]+=lz[node],lz[node*2+1]+=lz[node]; 
  lz[node]=0;
}
void upd(int node,int lo,int hi,int id,int vl)
{
  tooLazy(node,lo,hi);
  if(lo==hi){seg[node]=min(seg[node],vl);return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
}
void add(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]+=vl;tooLazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  add(node*2,lo,md,lt,rt,vl);add(node*2+1,md+1,hi,lt,rt,vl);
}
int get(int node,int lo,int hi,int id)
{
  tooLazy(node,lo,hi);
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  if(id<=md)return get(node*2,lo,md,id);
  else return get(node*2+1,md+1,hi,id); 
}
void dfs(int now)
{
  if(vis[now])
  {
    ent[now]=++tim;//cout<<now<<" ** "<<tim<<endl;
    upd(1,1,n,tim,tim);
  }
  else ent[now]=tim;
  for(int i=0;i<26;i++)
  {
    if(tr[now].nx[i])dfs(tr[now].nx[i]);
  }
  ext[now]=tim;
}
void dfs(int now,int h)
{
  //cout<<now<<" ** "<<h<<endl;
  int f=0;
  if(vis[now])
  {
    h=min(h,get(1,1,n,ent[now]));
    ans[vis[now]]=h;f=1;
  }
   //cout<<now<<" ** "<<h<<endl;
  if(ent[now]+1<=ext[now]&&-ent[now]+h+f<0)
  {
    //out<<now<<" "<<ent[now]+1<<" --> "<<ext[now]<<" "<<-ent[now]+h<<endl;
    add(1,1,n,ent[now]+1,ext[now],-ent[now]+h+f);
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
    cin>>kk[i];vis[kk[i]]=i;
  }
  dfs(0);dfs(0,0);
  // for(int i=0;i<=10;i++)
  //   cout<<i<<" "<<ent[i]<<" --> "<<ext[i]<<endl;
  for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
    cout<<endl;
     return 0;
}