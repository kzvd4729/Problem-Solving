/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-11 21:23:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-908
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int t,tc,n,m,u,v,w,tt,root[N+2],k;
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

  int f=0;
  while(cin>>n)
  {
    if(f)cout<<endl;
    f=1;

    tt=0;
    for(int i=1;i<n;i++)
    {
      cin>>u>>v>>w;
      tt+=w;
    }
    cout<<tt<<endl;

    cin>>k;
    for(int i=1;i<=k;i++)
    {
      cin>>u>>v>>w;
      p[i]={w,{u,v}};
    }
    cin>>m;
    m+=k;
    for(int i=k+1;i<=m;i++)
    {
      cin>>u>>v>>w;
      p[i]={w,{u,v}};
    }
    sort(p+1,p+m+1);
    cout<<minimum_spanning_tree()<<endl;
  }
  return 0;
}