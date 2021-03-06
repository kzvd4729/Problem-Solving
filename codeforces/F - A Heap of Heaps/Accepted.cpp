/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 12:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1652 ms                                         memory_used: 250100 KB                            
*  problem: https://codeforces.com/contest/538/problem/F
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
struct persistent
{
  int l,r,sm;
}seg[N*20+2];
int rot[N+2],nw;
void upd(int node,int pnode,int lo,int hi,int id)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+1;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;upd(seg[node].l,seg[pnode].l,lo,md,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;upd(seg[node].r,seg[pnode].r,md+1,hi,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int vl)
{
  if(lo>=vl)return 0;if(hi<vl)return seg[node].sm;
  int md=(lo+hi)/2;
  return get(seg[node].l,lo,md,vl)+get(seg[node].r,md+1,hi,vl);
}
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(aa[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];compress(n);
  for(int i=1;i<=n;i++)
  {
    rot[i]=++nw;upd(rot[i],rot[i-1],1,n,aa[i]);
  }
  for(int k=1;k<n;k++)
  {
    long cnt=0;
    for(int i=1;i<=n;i++)
    {
      int a=k*(i-1)+2,b=k*i+1;
      if(a>n&&b>n)break;if(b>n)b=n;
      cnt+=get(rot[b],1,n,aa[i])-get(rot[a-1],1,n,aa[i]);
    }
    cout<<cnt<<" ";
  }
  cout<<endl;
  return 0;
}