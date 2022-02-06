/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/27/2018 22:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 25800 KB                             
*  problem: https://codeforces.com/contest/1095/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2];
pair<long,long>aa[N+2];
struct edge
{
 int u,v;long w;
};
vector<edge>ed;
bool cmp(edge A,edge B)
{
 return A.w<B.w;
}
int _find(int x)
{
 if(x==par[x])return x;
 return par[x]=_find(par[x]);
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,m;cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>aa[i].first;aa[i].second=i;
 }
 sort(aa+1,aa+n+1);
 while(m--)
 {
  edge e;cin>>e.u>>e.v>>e.w;
  ed.push_back(e);
 }
 edge e;
 e.w=100000000000000000LL;
 ed.push_back(e);
 sort(ed.begin(),ed.end(),cmp);
 for(int i=1;i<=n;i++)par[i]=i;
 int p=0,p1=1,p2=2,cnt=0;long ans=0;
 while(cnt<n-1)
 {
  long one=ed[p].w,two=aa[p1].first+aa[p2].first;
  if(one<=two)
  {
   int r1=_find(ed[p].u),r2=_find(ed[p].v);
   if(r1!=r2)
   {
    ans+=ed[p].w;
    par[r1]=r2;cnt++;
   }
   p++;
  }
  else
  {
   int id1=aa[p1].second,id2=aa[p2].second;
   int r1=_find(id1),r2=_find(id2);
   if(r1!=r2)
   {
    par[r1]=r2;cnt++;
    ans+=two;
   }
   p2++;
   if(p2>n)
   {
    p1++;p2=p1+1;
   }
  }
 }
 cout<<ans<<endl;
 return 0;
}