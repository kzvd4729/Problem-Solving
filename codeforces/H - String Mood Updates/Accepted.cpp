/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2020 22:50                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1762 ms                                         memory_used: 76100 KB                             
*  problem: https://codeforces.com/gym/102644/problem/H
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
typedef vector<vector<int> > v2d;
/*
1 1 1   f[n]       f[n+1]
1 0 0 X f[n-1]  =  f[n]
0 1 0   f[n-2]     f[n-1]
*/
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);//impossible to multiply
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].resize(g,0);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d seg[4*N+8];string s;
void build(int node,int lo,int hi)
{
 if(lo==hi)
 {
  if(s[lo]=='H')seg[node]={{1,1},{0,0}};
  else if(s[lo]=='S'||s[lo]=='D')seg[node]={{0,0},{1,1}};
  else if(s[lo]=='?')seg[node]={{19,6},{7,20}};
  else if(s[lo]=='A'||s[lo]=='E'||s[lo]=='I'||s[lo]=='O'||s[lo]=='U')
   seg[node]={{0,1},{1,0}};
  else seg[node]={{1,0},{0,1}};
   return;
 }
 int md=(lo+hi)/2;
 build(node*2,lo,md);build(node*2+1,md+1,hi);
 seg[node]=multiply(seg[node*2+1],seg[node*2]);
}
void upd(int node,int lo,int hi,int id)
{
 if(lo==hi)
 {
  if(s[lo]=='H')seg[node]={{1,1},{0,0}};
  else if(s[lo]=='S'||s[lo]=='D')seg[node]={{0,0},{1,1}};
  else if(s[lo]=='?')seg[node]={{19,6},{7,20}};
  else if(s[lo]=='A'||s[lo]=='E'||s[lo]=='I'||s[lo]=='O'||s[lo]=='U')
   seg[node]={{0,1},{1,0}};
  else seg[node]={{1,0},{0,1}};
   return;
 }
 int md=(lo+hi)/2;
 if(id<=md)upd(node*2,lo,md,id);
 else upd(node*2+1,md+1,hi,id);
 seg[node]=multiply(seg[node*2+1],seg[node*2]); 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
   cin>>s;s="#"+s;
  build(1,1,n);
   cout<<seg[1][0][0]<<'\n';
  while(q--)
  {
   int id;char c;cin>>id>>c;s[id]=c;
   upd(1,1,n,id);cout<<seg[1][0][0]<<'\n';
  }
  return 0;
}