/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 655 ms                                          memory_used: 146100 KB                            
*  problem: https://codeforces.com/contest/1423/problem/H
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
const int N=1e6,inf=1e9;
vector<pair<int,int> >seg[4*N+8];
stack<pair<int,int> >st;
int par[N+2],sz[N+2];
void init(void)
{
  for(int i=1;i<=N;i++)par[i]=i,sz[i]=1;
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
  }
}
int qq[N+2];
void divide(int node,int lo,int hi)
{
  int now=st.size();//remembering the size before entering the segment
  for(auto x:seg[node])
  {
    int r1=find(x.first),r2=find(x.second);
    if(r1==r2)continue;
    if(sz[r1]>sz[r2])swap(r1,r2);
    par[r1]=r2;sz[r2]+=sz[r1];
    st.push({r1,r2});
  }
  if(lo==hi)
  {
    if(qq[lo])
    {
      int r=find(qq[lo]);
      cout<<sz[r]<<" ";
    }
    rollBack(now);return ;
  }
  int md=(lo+hi)/2;
  divide(node*2,lo,md);divide(node*2+1,md+1,hi);
  rollBack(now);
}
int ed[N+2],ty[N+2],u[N+2],v[N+2],x[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();
  int n,q,k;cin>>n>>q>>k;int day=0;
  for(int i=1;i<=q;i++)
  {
    cin>>ty[i];
    if(ty[i]==1)
    {
      cin>>u[i]>>v[i];if(u[i]>v[i])swap(u[i],v[i]);
    }
    else if(ty[i]==2)cin>>x[i];
    else ed[++day]=i;
  }
  ed[++day]=q;int cday=1;
  for(int i=1;i<=q;i++)
  {
    if(ty[i]==1)add(1,1,q,i,ed[min(day,cday+k-1)],{u[i],v[i]});
    else if(ty[i]==2)qq[i]=x[i];
    else cday++;
  }
  divide(1,1,q);cout<<endl;
  return 0;
}