/****************************************************************************************
*  @author: kzvd4729                                         created: 07-05-2021 17:13:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 72.9M                                
*  problem: https://www.codechef.com/MAY21A/problems/THOUSES
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
const int N=1e6,inf=1e9,mod=1e9+7;
vector<int>ad[N+2];
__int128 dp[N+2],x;
void dfs(int nd,int pr)
{
  vector<long>v;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);v.push_back(dp[x]);
  }
  sort(v.begin(),v.end(),greater<__int128>());
    dp[nd]=1;
  for(int i=1;i<=(int)v.size();i++)
    dp[nd]+=i*v[i-1];
  if(dp[nd]<0)assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,tmp;cin>>n>>tmp;x=tmp;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    dfs(1,-1);
    int ans=dp[1]%mod;
    cout<<(1LL*ans*tmp)%mod<<endl;
  }
      return 0;
}