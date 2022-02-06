/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 23:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 38500 KB                             
*  problem: https://codeforces.com/contest/1307/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int kk[N+2],n,aa[N+2],bb[N+2];
vector<int>adj[N+2];
void bfs1()
{
  for(int i=1;i<=n;i++)aa[i]=inf;
  queue<int>q;q.push(1);aa[1]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(aa[u]+1<aa[x])
      {
        aa[x]=aa[u]+1;q.push(x);
      }
    }
  }
}
void bfs2()
{
  for(int i=1;i<=n;i++)bb[i]=inf;
  queue<int>q;q.push(n);bb[n]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(bb[u]+1<bb[x])
      {
        bb[x]=bb[u]+1;q.push(x);
      }
    }
  }
}
int mx[N+2],nex[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)cin>>kk[i];
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  bfs1();bfs2();
   vector<pair<int,int> >v;v.push_back({-inf,-inf});
  for(int i=1;i<=k;i++)
    v.push_back({aa[kk[i]],bb[kk[i]]});
  sort(v.begin(),v.end());
   for(int i=k;i>=1;i--)
    mx[i]=max(mx[i+1],v[i].second);
   nex[n+1]=k+1;
  for(int i=1;i<=k;i++)nex[v[i].first]=i;
  for(int i=n;i>=0;i--)if(!nex[i])nex[i]=nex[i+1];
   /*for(int i=0;i<=5;i++)
    cout<<nex[i]<<" ";
  cout<<endl;*/
   //for(int i=1;i<=k;i++)cout<<v[i].first<<" -- "<<v[i].second<<endl;
   int mxm=0;
  for(int i=1;i<k;i++)
  {
    int lo=0,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int rq=max(0,md-v[i].second);
      //cout<<md<<endl;
      if(nex[rq]>k)
      {
        //cout<<md<<endl;
        hi=md;
      }
      else
      {
        //cout<<md<<endl;
        int nx=max(nex[rq],i+1);
        //cout<<"*"<<nx<<endl;
        if(v[i].first+mx[nx]<md)hi=md;
        else lo=md;
      }
    }
    int f=0;//cout<<lo<<" "<<hi<<endl;
    for(md=hi;md>=lo;md--)
    {
      int rq=max(0,md-v[i].second);
      if(nex[rq]>k);
      else
      {
        int nx=max(nex[rq],i+1);
        if(v[i].first+mx[nx]<md);
        else
        {
          f=1;break;
        }
      }
    }
    //cout<<md<<endl;
    //cout<<"*"<<f<<endl;
    mxm=max(mxm,md+1);
    //exit(0);
  }
  cout<<min(aa[n],mxm)<<endl;
  return 0;
}