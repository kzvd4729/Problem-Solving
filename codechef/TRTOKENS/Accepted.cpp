/****************************************************************************************
*  @author: kzvd4729                                         created: 01-06-2021 19:33:34                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.88 sec                                        memory_used: 124.4M                               
*  problem: https://www.codechef.com/problems/TRTOKENS
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1000000007;
pair<int,int>seg[4*N+8];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]={-1,-1};return ;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int id,pair<int,int>vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-1,-1};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(node*2,lo,md,lt,rt);
  pair<int,int>p2=get(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
int p[N+2],lv[N+2],ent[N+2],ext[N+2],tim,n;
vector<int>ad[N+2];string s;
void dfs(int nd,int pr,int l)
{
  lv[nd]=l;ent[nd]=++tim;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd,l+1);
  }
  ext[nd]=tim;
}
void dfs2(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs2(x,nd);
  }
  if(s[nd]=='1')
  {
    upd(1,1,n,ent[nd],{lv[nd],nd});
    return ;
  }
    pair<int,int>p=get(1,1,n,ent[nd],ext[nd]);
  if(p.first==-1)return ;
  upd(1,1,n,ent[p.second],{-1,-1});
  swap(s[nd],s[p.second]);
  upd(1,1,n,ent[nd],{lv[nd],nd});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;cin>>s;s="#"+s;build(1,1,n);tim=0;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=2;i<=n;i++)
    {
      cin>>p[i];
      ad[p[i]].push_back(i);
    }
    dfs(1,-1,0);
    long tt=0;
    for(int i=1;i<=n;i++)if(s[i]=='1')tt+=lv[i];
    dfs2(1,-1);
    for(int i=1;i<=n;i++)if(s[i]=='1')tt-=lv[i];
    cout<<tt<<'\n';
      }
  return 0;
}