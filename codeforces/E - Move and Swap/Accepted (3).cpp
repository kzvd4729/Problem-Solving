/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 15:11                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1075 ms                                         memory_used: 96300 KB                             
*  problem: https://codeforces.com/contest/1485/problem/E
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
  long a[N+2],dp[N+2],d,mx[N+2],fr[N+2],bk[N+2];
vector<int>ad[N+2],lv[N+2];
  void dfs(int nd,int pr,int l)
{
  lv[l].push_back(nd);d=max(d,1LL*l);
  for(auto x:ad[nd])
    if(x!=pr)dfs(x,nd,l+1);
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)ad[i].clear(),lv[i].clear();
    for(int i=2;i<=n;i++)
    {
      int x;cin>>x;
      ad[i].push_back(x);ad[x].push_back(i);
    }
    for(int i=2;i<=n;i++)cin>>a[i];
    dfs(1,-1,0);
     for(int i=1;i<=n;i++)mx[i]=0,dp[i]=0;
    for( ;d>=0;d--)
    {
      sort(lv[d].begin(),lv[d].end(),[&](int i,int j){
        return a[i]<a[j];
      });
       for(auto nd:lv[d])
      {
        for(auto x:ad[nd])mx[nd]=max(mx[nd],dp[x]);
      }
       for(auto nd:lv[d])
      {
        dp[nd]=mx[nd]+max(abs(a[nd]-a[lv[d][0]]),abs(a[nd]-a[lv[d].back()]));
      }
      //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
      //for(auto x:lv[d])cout<<x<<" ";cout<<endl;
       fr[0]=mx[lv[d][0]]-a[lv[d][0]];
      for(int i=1;i<(int)lv[d].size();i++)
      {
        fr[i]=max(fr[i-1],mx[lv[d][i]]-a[lv[d][i]]);
      }
       int sz=lv[d].size()-1;
      bk[sz]=mx[lv[d][sz]]+a[lv[d][sz]];
      for(int i=sz-1;i>=0;i--)
      {
        bk[i]=max(bk[i+1],mx[lv[d][i]]+a[lv[d][i]]);
      }
       for(int i=0;i<(int)lv[d].size();i++)
      {
        int x=lv[d][i];
        dp[x]=max(dp[x],max(fr[i]+a[x],bk[i]-a[x]));
      }
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
    cout<<dp[1]<<'\n';
  }
  return 0;
}