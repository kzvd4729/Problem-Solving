/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2021 15:44                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++17 (64)                          
*  run_time: 1903 ms                                         memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1559/problem/D2
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int N=1e5;
 struct dsu
{
  int par[N+2];
  void set(int n)
  {
    for(int i=1;i<=n;i++)par[i]=i;
  }
  int get(int x)
  {
    if(x==par[x])return x;
    return par[x]=get(par[x]);
  }
  bool isConnected(int u,int v)
  {
    if(get(u)==get(v))return true;
    return false;
  }
  void connect(int u,int v)
  {
    par[get(u)]=get(v);
  }
}a,b;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m1,m2;cin>>n>>m1>>m2;
   a.set(n),b.set(n);
  for(int i=1;i<=m1;i++)
  {
    int u,v;cin>>u>>v;
    a.connect(u,v);
  }
  for(int i=1;i<=m2;i++)
  {
    int u,v;cin>>u>>v;
    b.connect(u,v);
  }
   cout<<n-1-max(m1,m2)<<endl;
   while(clock()<CLOCKS_PER_SEC*1.9)
  {
    int i=1+rng()%n,j=1+rng()%n;
    if(a.isConnected(i,j)==0 && b.isConnected(i,j)==0)
    {
      cout<<i<<" "<<j<<endl;
      a.connect(i,j),b.connect(i,j);
    }
  }
    return 0;
}