/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 22:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 90000 KB                             
*  problem: https://codeforces.com/contest/379/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6+10;
int sp[N+2][20+2],lev[N+2];
void upd(int u,int p)
{
  sp[u][0]=p;lev[u]=lev[p]+1;
  for(int j=1;j<=20;j++)
  {
    if(sp[u][j-1]!=-1)
      sp[u][j]=sp[sp[u][j-1]][j-1];
  }
}
int dist(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);int d=0;
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i],d+=(1<<i);
  }
  if(u==v)return d;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i],d+=2*(1<<i);
  }
  return d+2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(sp,-1,sizeof(sp));
  upd(2,1),upd(3,1),upd(4,1);int u=2,v=4,d=2,n=4;
   int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
     ++n;upd(n,x);
    if(dist(u,n)>d)d=dist(u,n),v=n;
    if(dist(v,n)>d)d=dist(v,n),u=n;
     ++n;upd(n,x);
    if(dist(u,n)>d)d=dist(u,n),v=n;
    if(dist(v,n)>d)d=dist(v,n),u=n;
     cout<<d<<"\n";
  }
  return 0;
}