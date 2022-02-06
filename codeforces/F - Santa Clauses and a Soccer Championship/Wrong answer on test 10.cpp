/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2019 17:52                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 90200 KB                             
*  problem: https://codeforces.com/contest/752/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int n,tem[N+2],ent[N+2],ext[N+2],tim,lin[N+2];
vector<int>adj[N+2];
 pair<int,int>seg[5*N+2];int sum[5*N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]={vl,id};sum[node]=1;
    if(vl==-inf)sum[node]=0;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
  sum[node]=sum[node*2]+sum[node*2+1];
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-inf,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(node*2,lo,md,lt,rt);
  pair<int,int>p2=get(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
int getSz(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return sum[node];
  int md=(lo+hi)/2;
  int p1=getSz(node*2,lo,md,lt,rt);
  int p2=getSz(node*2+1,md+1,hi,lt,rt);
  return p1+p2;
}
void dfs(int node,int par,int l)
{
  ent[node]=++tim;lin[tim]=node;
  if(tem[node])upd(1,1,n,tim,l);else upd(1,1,n,tim,-inf);
   for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,l+1);
  }
  ext[node]=tim;
}
vector<pair<int,int> >ans;int center;
void dfs2(int node,int par)
{
  priority_queue<pair<int,int> >pq;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    int sz=getSz(1,1,n,ent[x],ext[x]);
    if(sz)pq.push({sz,x});
    //cout<<"*"<<sz<<endl;
  }
  while(pq.size()>=2)
  {
    pair<int,int>p1=pq.top();pq.pop();
    pair<int,int>p2=pq.top();pq.pop();
     int a=get(1,1,n,ent[p1.second],ext[p1.second]).second;
    int b=get(1,1,n,ent[p2.second],ext[p2.second]).second;
    //cout<<a<<" --> "<<b<<endl;
    ans.push_back({lin[a],lin[b]});
    if(p1.first>1)pq.push({p1.first-1,p1.second});
    if(p2.first>1)pq.push({p2.first-1,p2.second});
    upd(1,1,n,a,-inf);upd(1,1,n,b,-inf);
  }
  if(getSz(1,1,n,ent[node],ent[node])&&pq.size())
  {
    //cout<<"here"<<endl;
    pair<int,int>p1=pq.top();pq.pop();
    int a=get(1,1,n,ent[p1.second],ext[p1.second]).second;
     ans.push_back({node,lin[a]});
    if(p1.first>1)pq.push({p1.first-1,p1.second});
    upd(1,1,n,a,-inf);
  }
  if(pq.size()==0)center=node;
  else dfs2(pq.top().second,node);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=k+k;i++)
  {
    int x;cin>>x;tem[x]=1;
  }
  dfs(1,-1,0);
   //cout<<"ok"<<endl;
   dfs2(1,-1);cout<<1<<"\n";
  cout<<center<<" "<<"\n";
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<" "<<center<<"\n";
   return 0;
}