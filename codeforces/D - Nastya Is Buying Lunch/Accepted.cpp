/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2020 14:44                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 468 ms                                          memory_used: 33400 KB                             
*  problem: https://codeforces.com/contest/1136/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
    sort(adj[i].begin(),adj[i].end());
  set<int>st;st.insert(a[n]);
  int ans=0;
  for(int i=n-1;i>=1;i--)
  {
    int f=1;
    for(auto x:st)
    {
      if(!binary_search(adj[a[i]].begin(),adj[a[i]].end(),x)){f=0;break;}
    }
    if(f==0)st.insert(a[i]);
    else ans++;
  }
  cout<<ans<<endl;
  return 0;
}