/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2018 20:16                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/742/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=1000;
int n,m,w,ww[N+2],bb[N+2];
int root[N+2],dp[N+2][N+2];
vector<int>vv[N+2];
struct data
{
  int next,wi,bi;
}arr[N+2];
int find_root(int node)
{
  if(root[node]==node)return node;
  return root[node]=find_root(root[node]);
}
int dfs(int ii,int wg)
{
  if(wg>w)return -inf;
  if(ii>n)return 0;
  if(dp[ii][wg]!=-1)return dp[ii][wg];
  int here=0,ww=0,bb=0;
  for(int i=ii;i<arr[ii].next;i++)
  {
    ww+=arr[i].wi;
    bb+=arr[i].bi;
    here=max(here,arr[i].bi+dfs(arr[ii].next,wg+arr[i].wi));
  }
  here=max(here,bb+dfs(arr[ii].next,wg+ww));
  return dp[ii][wg]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>w;
  for(int i=1;i<=n;i++)
    cin>>ww[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  for(int i=1;i<=n;i++)
    root[i]=i;
  while(m--)
  {
    int u,v;cin>>u>>v;
    int r1=find_root(u);
    int r2=find_root(v);
    root[r1]=r2;
  }
  for(int i=1;i<=n;i++)
  {
    int r=find_root(i);
    vv[r].push_back(i);
  }
  int id=0;
  for(int i=1;i<=n;i++)
  {
    int nx=id+vv[i].size()+1;
    for(auto xx:vv[i])
    {
      ++id;
      arr[id].next=nx;
      arr[id].wi=ww[xx];
      arr[id].bi=bb[xx];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}