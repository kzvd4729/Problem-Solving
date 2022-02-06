/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 11:42                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/1101/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n,ans,mx[N+2];
vector<int>dd[N+2];
void divisors(int n)
{
  for(int i=2;i<=n;i++)
  {
    for(int j=i;j<=n;j+=i)
    {
      dd[j].push_back(i);
    }
  }
}
/*********** Centroid Decomposition ************/
int Tot,Mark[N+2],Sz[N+2];
vector<int>Adj[N+2];
void Reckon(int node,int par)
{
  Tot++;Sz[node]=1;
  for(auto x:Adj[node])
  {
    if(Mark[x]||x==par)continue;
    Reckon(x,node);Sz[node]+=Sz[x];
  }
}
int Find_Center(int node,int par)
{
  for(auto x:Adj[node])
  {
    if(x==par||Mark[x])continue;
    if(Sz[x]>Tot/2)return Find_Center(x,node);
  }
  return node;
}
void add(int node,int par,int gc,int hg)
{
  mx[gc]=max(mx[gc],hg);
  for(auto x:Adj[node])
  {
    if(Mark[x]||x==par)continue;
    add(x,node,__gcd(gc,aa[x]),hg+1);
  }
}
void cal(int node,int par,int gc,int hg,int nm)
{
  for(auto x:dd[nm])
    if(__gcd(gc,x)>1)
      ans=max(ans,hg+mx[x]);
  for(auto x:Adj[node])
  {
    if(Mark[x]||x==par)continue;
    add(x,node,__gcd(gc,aa[x]),hg+1);
  }
}
void Centroid(int node,int par)
{
  Tot=0;Reckon(node,-1);
  int center=Find_Center(node,-1);
  Mark[center]=1;
   //cal //clear
  if(aa[center]>1)ans=max(ans,1);
  mx[aa[center]]=1;
  for(auto x:Adj[center])
  {
    if(Mark[x])continue;
    cal(x,center,__gcd(aa[x],aa[center]),1,aa[center]);
    add(x,center,aa[x],2);
  }
  for(auto x:dd[aa[center]])mx[x]=0;
   for(auto x:Adj[center])
  {
    if(Mark[x])continue;
    Centroid(x,center);
  }
}
/////////////////////////////////////////////////
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors(N);cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Centroid(1,-1);cout<<ans<<endl;
  return 0;
}