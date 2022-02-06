/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 17:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/265/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],n,x,ans[N+2],pr;
vector<int>fac[N+2];
void prime_factorize(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      fac[j].push_back(i);
      vis[j]=1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   prime_factorize();
   cin>>n;
  pr=1;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    int here=0;
    for(auto xx:fac[x])
      here=max(here,ans[xx]);
    for(auto xx:fac[x])
    {
      ans[xx]=here+1;
      pr=max(pr,ans[xx]);
    }
  }
  cout<<pr<<endl;
  return 0;
}