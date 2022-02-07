/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-11 20:26:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 290                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11631
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int t,tc,n,m,u,v,w,tt,root[N+2];
pair<int,pair<int,int> >p[N+2];
int find_root(int x)
{
  while(x!=root[x])
  {
    root[x]=root[root[x]];
    x=root[x];
  }
  return x;
}
int minimum_spanning_tree(void)
{
  for(int i=0;i<=n;i++)root[i]=i;
  int mst=0;
  for(int i=1;i<=m;i++)
  {
    int uu=p[i].second.first;
    int vv=p[i].second.second;
    int ww=p[i].first;
    int r1=find_root(uu);
    int r2=find_root(vv);
    if(r1==r2)continue;
    mst+=ww;
    root[r1]=r2;
  }
  return mst;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n>>m)
  {
    if(!n&&!m)break;
    tt=0;
    for(int i=1;i<=m;i++)
    {
      cin>>u>>v>>w;
      p[i]={w,{u,v}};
      tt+=w;
    }
    sort(p+1,p+m+1);
    cout<<tt-minimum_spanning_tree()<<endl;
  }
  return 0;
}