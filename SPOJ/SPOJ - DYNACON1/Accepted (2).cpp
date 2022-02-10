/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-16 19:11:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 350                                        memory_used (MB): 34.8                            
*  problem: https://vjudge.net/problem/SPOJ-DYNACON1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
map<pair<int,int>,vector<pair<int,int> > >mp;
vector<pair<int,int> >seg[5*N+2];
vector<vector<int> >qr;stack<pair<int,int> >st;
int tim,q,n,component,track[N+2],cnt,par[N+2],sz[N+2],ans[N+2];
void init(void)
{
  for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
  component=n;
}
void clear()
{
  mp.clear();cnt=0,tim=0;qr.clear();
  while(st.size())st.pop();
  for(int i=0;i<=N;i++)track[i]=0;
  for(int i=0;i<=5*N;i++)
    seg[i].clear();
}
void add(int node,int lo,int hi,int lt,int rt,pair<int,int>p)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].push_back(p);return ;
  }
  int md=(lo+hi)/2;
  add(node*2,lo,md,lt,rt,p);
  add(node*2+1,md+1,hi,lt,rt,p);
}
int find(int x)
{
  if(x==par[x])return x;
  return find(par[x]);//no path compression
}
void rollBack(int now)//deleting what was added in this segment
{
  while(st.size()>now)
  {
    int r1=st.top().first,r2=st.top().second;st.pop();
    par[r1]=r1;sz[r2]-=sz[r1];
    component++;
  }
}
void divide(int node,int lo,int hi)
{
  int now=st.size();//remembering the size before entering the segment
  for(auto x:seg[node])
  {
    int r1=find(x.first),r2=find(x.second);
    if(r1==r2)continue;
    if(sz[r1]>sz[r2])swap(r1,r2);
    par[r1]=r2;sz[r2]+=sz[r1];
    st.push({r1,r2});component--;
  }
  if(lo==hi)
  {
    if(track[lo])
      ans[qr[track[lo]-1][0]]=(find(qr[track[lo]-1][1])==find(qr[track[lo]-1][2]));
    rollBack(now);return ;
  }
  int md=(lo+hi)/2;
  divide(node*2,lo,md);divide(node*2+1,md+1,hi);
  rollBack(now);
}
void addQuery(int ty,int u,int v)
{
  if(u>v)swap(u,v);++tim;
  if(ty==3)track[tim]=qr.size()+1,qr.push_back({++cnt,u,v});
  else
  {
    if(ty==1)mp[{u,v}].push_back({tim,q});//active from tm to end;
    else mp[{u,v}].back().second=tim;//edge is removed;
  }
}
void solve()
{
  //add all query to the segment tree
  for(auto x:mp)
    for(auto z:x.second)
      add(1,1,q,z.first,z.second,x.first);
  divide(1,1,q);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;init();
  for(int i=1;i<=q;i++)
  {
    string ch;cin>>ch;int u,v;cin>>u>>v;
    if(ch=="conn")addQuery(3,u,v);
    else if(ch=="add")addQuery(1,u,v);
    else addQuery(2,u,v);
  }
  solve();
  for(int i=1;i<=cnt;i++)
  {
    if(ans[i])cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}