/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 18:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 16400 KB                             
*  problem: https://codeforces.com/contest/690/problem/C3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int sp[N+2][20],lev[N+2];
void add(int n,int p)
{
  sp[n][0]=p;
  for(int i=1;i<20;i++)
    if(sp[n][i-1]!=-1)sp[n][i]=sp[sp[n][i-1]][i-1];
}
int dis(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  int d=0;
  for(int i=20-1;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i],d+=(1<<i);
  }
  if(u==v)return d;
  for(int i=20-1;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];d+=2*(1<<i);
  }
  return d+2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;memset(sp,-1,sizeof(sp));
  int u=1,v=1,pr=0;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;add(i,x);
    lev[i]=lev[x]+1;
    int a=dis(u,i),b=dis(v,i);
    if(max(a,b)<=pr){cout<<pr<<" ";continue;}
    if(a>b){cout<<a<<" ";v=i;}
    else {cout<<b<<" ";u=i;}
    pr=max(a,b);
  }
  cout<<endl;
  return 0;
}