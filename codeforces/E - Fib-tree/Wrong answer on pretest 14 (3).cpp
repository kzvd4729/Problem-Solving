/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 22:32                        
*  solution_verdict: Wrong answer on pretest 14              language: GNU C++17 (64)                          
*  run_time: 295 ms                                          memory_used: 71400 KB                             
*  problem: https://codeforces.com/contest/1491/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>ad[N+2],nm[N+2];
int f[N+2],fib[N+2],vs[N+2],sub[N+2];
 void reckon(int nd,int pr)
{
  sub[nd]=1;
  int sz=ad[nd].size();
  for(int i=0;i<sz;i++)
  {
    if(ad[nd][i]==pr)continue;
    if(vs[nm[nd][i]])continue;
    reckon(ad[nd][i],nd);
    sub[nd]+=sub[ad[nd][i]];
  }
}
vector<vector<int> >v;
void dfs(int tt,int nd,int pr)
{
  int sz=ad[nd].size();
  for(int i=0;i<sz;i++)
  {
    int x=ad[nd][i];
    if(x==pr)continue;
    if(vs[nm[nd][i]])continue;
    if(fib[sub[x]]&&fib[tt-sub[x]])v.push_back({nd,x,nm[nd][i]});
    dfs(tt,x,nd);
  }
}
bool reach(int nd,int b,int pr)
{
  if(nd==b)return true;
  int sz=ad[nd].size();
  int ret=false;
  for(int i=0;i<sz;i++)
  {
    int x=ad[nd][i];
    if(x==pr)continue;
    if(vs[nm[nd][i]])continue;
     ret|=reach(x,b,nd);
  }
  return ret;
}
bool centroid(int nd)
{
  reckon(nd,-1);
  if(sub[nd]<=3)return true;
  if(fib[sub[nd]]==0)return false;
   v.clear();
  dfs(sub[nd],nd,-1);
  if((int)v.size()==0)return false;
  //if((int)v.size()>1)assert(0);
  if((int)v.size()==1)
  {
    vs[v[0][2]]=1;
    //cout<<v[0][0]<<" "<<v[0][1]<<endl;
    return (centroid(v[0][0])&centroid(v[0][1]));
  }
  else
  {
    vs[v[1][2]]=1;
    //cout<<v[0][0]<<" "<<v[0][1]<<endl;
    return (centroid(v[1][0])&centroid(v[1][1]));
     int a=v[0][0],b=v[0][1],c=v[1][0],d=v[1][1];
    vs[v[0][2]]=1;vs[v[1][2]]=1;
     //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
     bool ret=1;
    if(reach(a,c,-1))
    {
      ret&=centroid(a);
      ret&=centroid(b);
      ret&=centroid(d);
    }
    else if(reach(a,d,-1))
    {
      ret&=centroid(a);
      ret&=centroid(b);
      ret&=centroid(c);
    }
    else if(reach(b,c,-1))
    {
      ret&=centroid(a);
      ret&=centroid(b);
      ret&=centroid(d);
    }
    else if(reach(b,d,-1))
    {
      ret&=centroid(a);
      ret&=centroid(b);
      ret&=centroid(c);
    }
    return ret;
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   f[0]=1;
  f[1]=1;fib[1]=1;
  for(int i=2;i<=26;i++)
  {
    f[i]=f[i-1]+f[i-2];
    fib[f[i]]=1;
    //cout<<i<<" "<<f[i]<<endl;
  }
  //exit(0);
  //cout<<f[26]<<endl;
   int n;cin>>n;
  if(fib[n]==0)cout<<"NO"<<endl,exit(0);
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
     nm[u].push_back(i);nm[v].push_back(i);
  }
  if(centroid(1))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
     return 0;
}