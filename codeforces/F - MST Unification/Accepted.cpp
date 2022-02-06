/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 14:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 18500 KB                             
*  problem: https://codeforces.com/contest/1108/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int anc[N+2];
struct data
{
  int u,v,w;
}st[N+2];
bool cmp(data A,data B)
{
  return A.w<B.w;
}
int _find(int x)
{
  if(anc[x]==x)return x;
  return anc[x]=_find(anc[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>st[i].u>>st[i].v>>st[i].w;
  sort(st+1,st+m+1,cmp);st[m+1]={1,n,2000000000};
  for(int i=1;i<=n;i++)anc[i]=i;
  int pr=st[1].w;vector<int>v;int ans=0;
  for(int i=1;i<=m+1;i++)
  {
    if(st[i].w==pr)
    {
      int r1=_find(st[i].u),r2=_find(st[i].v);
      if(r1!=r2)
        v.push_back(i);
    }
    else
    {
      for(auto x:v)
      {
        int r1=_find(st[x].u),r2=_find(st[x].v);
        if(r1!=r2)anc[r1]=r2;
        else ans++;
      }
      v.clear();pr=st[i].w;
      i--;
    }
  }
  cout<<ans<<endl;
  return 0;
}