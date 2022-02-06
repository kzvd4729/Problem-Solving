/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/07/2020 11:54                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/796/problem/C
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
const int N=1e6;
int aa[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=-1e9;
  for(int i=1;i<=n;i++)cin>>aa[i],mx=max(mx,aa[i]);
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int ans=mx;
  for(int i=1;i<=n;i++)
  {
    int a=0,b=0;
    for(auto x:adj[i])
    {
      if(aa[i]==mx&&aa[x]==mx)ans=max(ans,mx+1);
      if(aa[x]==mx-1)a++;
      if(aa[x]==mx)b++;
    }
    if(b>1)ans=max(ans,mx+2);
    if(a>1)ans=max(ans,mx+1);
  }
  cout<<ans<<endl;
  return 0;
}