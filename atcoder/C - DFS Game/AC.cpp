/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-28 15:58:57                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 52 ms                                           memory_used: 48428 KB                             
*  problem: https://atcoder.jp/contests/arc112/tasks/arc112_c
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
const int N=1e6,inf=1e9,mod=1000000007;
 vector<int>ad[N+2];
int sub[N+2],dp[N+2][2],fir=0,sec=1;
 void dfs(int nd,int pr)
{
  sub[nd]=1;dp[nd][fir]=1;
  vector<pair<int,int> >od,ev;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
     dfs(x,nd);sub[nd]+=sub[x];
     if(sub[x]%2==0)ev.push_back({dp[x][fir],dp[x][sec]});
    else od.push_back({dp[x][fir],dp[x][sec]});
  }
   if((int)od.size()%2==0)
  {
    for(auto x:ev)
    {
      dp[nd][fir]+=x.first;
      dp[nd][sec]+=x.second;
    }
  }
  else 
  {
    for(auto x:ev)
    {
      dp[nd][fir]+=min(x.first,x.second);
      dp[nd][sec]+=max(x.first,x.second);
    }
  }
   sort(od.begin(),od.end(),[](pair<int,int>a,pair<int,int>b){
    return a.second-a.first>b.second-b.first;
  });
   for(int i=0;i<(int)od.size();i+=2)
    dp[nd][fir]+=od[i].first,dp[nd][sec]+=od[i].second;
   for(int i=1;i<(int)od.size();i+=2)
    dp[nd][fir]+=od[i].second,dp[nd][sec]+=od[i].first;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    ad[x].push_back(i);
  }
  dfs(1,-1);
  cout<<dp[1][fir]<<endl;
    return 0;
}