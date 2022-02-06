/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2018 22:36                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/893/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=1e5;
int n,q,bt[N+2],hg[N+2],arr[N+2],k;
int tim,st[N+2],ed[N+2],ad[N+2],u,v;
vector<int>adj[N+2];
vector<pair<int,int> >seg[4*N];
void dfs(int node,int par,int h)
{
  ++tim;
  arr[tim]=node;
  st[node]=tim;
  hg[node]=h;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    dfs(xx,node,h+1);
  }
  ed[node]=tim;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node].push_back({hg[arr[lo]],bt[arr[lo]]});
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
    vector<pair<int,int> >v1=seg[node*2];
  vector<pair<int,int> >v2=seg[node*2+1];
   int i=0,j=0;
  int last=1e9;
  while(i<v1.size()&&j<v2.size())
  {
    if(i<v1.size()&&j<v2.size())
    {
      if(v1[i].first<v2[j].first)
      {
        seg[node].push_back({v1[i].first,min(last,v1[i].second)});
        i++;
      }
      else
      {
        seg[node].push_back({v2[j].first,min(last,v2[j].second)});
        j++;
      }
    }
    else if(i<v1.size())
    {
      seg[node].push_back({v1[i].first,min(last,v1[i].second)});
      i++;
    }
    else
    {
      seg[node].push_back({v2[j].first,min(last,v2[j].second)});
      j++;
    }
    last=min(last,seg[node].back().second);
  }
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)
  {
    int id=upper_bound(seg[node].begin(),seg[node].end(),make_pair(k,inf+1))-seg[node].begin();
    id--;
    return seg[node][id].second;
  }
  int md=(lo+hi)/2;
  return min(query(node*2,lo,md,lt,rt),query(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>bt[i];
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);
  build(1,1,n);
 //  cout<<"goes here "<<endl;
//  for(int i=st[1];i<=ed[1];i++)
//    cout<<arr[i]<<" ";
//  cout<<endl;
   int x,p,q,last=0;
  while(q--)
  {
    cin>>p>>q;
    x=(p+last)%n+1;
    k=(q+last)%n;
    k+=hg[x];
    last=query(1,1,n,st[x],ed[x]);
    cout<<last<<endl;
  }
  return 0;
}