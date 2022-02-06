/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2020 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 25800 KB                             
*  problem: https://codeforces.com/contest/1285/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=2e9;
int tr[N*33][2],sz;
void insrt(int x)
{
  int now=0;
  for(int i=30;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(!tr[now][z])tr[now][z]=++sz;
    now=tr[now][z];
  }
}
int dfs(int now,int d)
{
  if((!tr[now][0])&&(!tr[now][1]))return 0;
   int ret=inf;
  if(tr[now][0]&&(!tr[now][1]))return dfs(tr[now][0],d-1);
  if(tr[now][1]&&(!tr[now][0]))return dfs(tr[now][1],d-1);
   return min(dfs(tr[now][0],d-1),dfs(tr[now][1],d-1))+(1<<d);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;insrt(x);
  }
  cout<<dfs(0,30)<<endl;
    return 0;
}