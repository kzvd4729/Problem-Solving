/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 14:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1029 ms                                         memory_used: 15000 KB                             
*  problem: https://codeforces.com/contest/855/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>v;
int b;
void con(long x)
{
  v.clear();
  while(x)
  {
    v.push_back(x%b);x/=b;
  }
  reverse(v.begin(),v.end());
}
long mm[64+2][(1<<10)+2][2][10+2];
long dfs2(int rm,int msk,int f,int b)
{
  if(rm==0)return ((bool)(!msk))&f;
  if(mm[rm][msk][f][b]!=-1)return mm[rm][msk][f][b];
  long ret=0;
  for(int j=0;j<b;j++)
  {
    if(f==0)
    {
      if(j==0)ret+=dfs2(rm-1,msk,0,b);
      else ret+=dfs2(rm-1,msk^(1<<j),1,b);
    }
    else ret+=dfs2(rm-1,msk^(1<<j),1,b);
  }
  return mm[rm][msk][f][b]=ret;
}
long dp[64+2][(1<<10)+2][2][2];vector<vector<int> >bf;
long dfs(int i,int msk,int ck,int f)
{
  if(i==v.size())return ((bool)(!msk))&f;
  if(ck==0)return dfs2(v.size()-i,msk,f,b);
  if(dp[i][msk][ck][f]!=-1)return dp[i][msk][ck][f];
  long ret=0;
  for(int j=0;j<v[i];j++)
  {
    if(f==0)
    {
      if(j==0)ret+=dfs(i+1,msk,0,0);
      else ret+=dfs(i+1,msk^(1<<j),0,1);
    }
    else ret+=dfs(i+1,msk^(1<<j),0,1);
  }
  ret+=dfs(i+1,msk^(1<<v[i]),1,1);
  bf.push_back({i,msk,ck,f});
  return dp[i][msk][ck][f]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(mm,-1,sizeof(mm));memset(dp,-1,sizeof(dp));
  int q;cin>>q;
  while(q--)
  {
    long l,r;cin>>b>>l>>r;con(r);
    long a=dfs(0,0,1,0);for(auto x:bf)dp[x[0]][x[1]][x[2]][x[3]]=-1;bf.clear();
    con(l-1);
    cout<<a-dfs(0,0,1,0)<<"\n";for(auto x:bf)dp[x[0]][x[1]][x[2]][x[3]]=-1;bf.clear();
  }
  return 0;
}