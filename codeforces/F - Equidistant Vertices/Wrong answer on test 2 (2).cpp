/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2021 16:42                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 0 ms                                            memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/1551/problem/F
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
const int N=100,inf=1e9,mod=1e9+7;
 vector<int>ad[N+2];
int k,ans;
 int ncr[N+2][N+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;////use mod
  }
  ncr[0][0]=1;
}
 int mx;
void reckon(int nd,int pr,int l)
{
  mx=max(mx,l);
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    reckon(x,nd,l+1);
  }
}
vector<int>dfs(int nd,int pr,int l,int rt)
{
  vector<int>v(mx+1,0);v[l]++;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    vector<int>tmp=dfs(x,nd,l+1,rt);
     for(int i=1;i<=mx;i++)
    {
      if(nd==rt)ans=(ans-ncr[tmp[i]][k])%mod;
      v[i]+=tmp[i];
    }
  }
   //cout<<nd<<"   ";
  for(int i=1;i<=mx;i++)
  {
    //cout<<v[i]<<" ";
    if(nd==rt)ans=(ans+ncr[v[i]][k])%mod;
  }
  //cout<<endl;
  return v;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   calNCR(N);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>k;
     for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
     if(k==2)
    {
      cout<<ncr[n][2]<<endl;
      continue;
    }
     ans=0;
    for(int i=1;i<=n;i++)
    {
      mx=0;reckon(i,0,1);
      dfs(i,0,1,i);
    }
    cout<<(ans+mod)%mod<<endl;
  }
  return 0;
}