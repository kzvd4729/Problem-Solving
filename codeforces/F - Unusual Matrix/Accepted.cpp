/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 19:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 33100 KB                             
*  problem: https://codeforces.com/contest/1475/problem/F
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
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=998244353;
 string a[N+2],b[N+2];int cl[N+2];
vector<pair<int,int> >ad[N+2];
 bool dfs(int nd,int c)
{
  if(cl[nd]!=-1)
  {
    if(cl[nd]!=c)return false;
    return true;
  }
  cl[nd]=c;bool ret=1;
   for(auto x:ad[nd])ret&=dfs(x.first,c^x.second);
   return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]="#"+a[i];
    for(int i=1;i<=n;i++)cin>>b[i],b[i]="#"+b[i];
         for(int i=1;i<=n+n;i++)ad[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        int cl=1;
        if(a[i][j]==b[i][j])cl=0;
         ad[i].push_back({n+j,cl});
        ad[n+j].push_back({i,cl});
      }
    }
     for(int i=1;i<=n+n;i++)cl[i]=-1;
    if(dfs(1,0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
      }
  return 0;
}