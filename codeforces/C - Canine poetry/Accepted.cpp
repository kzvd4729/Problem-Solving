/****************************************************************************************
*  @author: kzvd4729#                                        created: May/02/2021 13:32                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 156 ms                                          memory_used: 29900 KB                             
*  problem: https://codeforces.com/contest/1466/problem/C
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
const int N=1e5,inf=1e9,mod=1e9+7;
 //int dp[N+2][26+2][26+2];
map<int,int>dp[26+2][26+2];
 string s;
int dfs(int id,int a,int b)
{
  if(id>=(int)s.size())return 0;
   if(dp[a][b].count(id))return dp[a][b][id];
  //if(dp[id][a][b]!=-1)return dp[id][a][b];
    int ret=1+dfs(id+1,b,26);
   if((s[id]-'a'!=a) && (s[id]-'a'!=b))
    ret=min(ret,dfs(id+1,b,s[id]-'a'));
   return dp[a][b][id]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>s;
     if((int)s.size()==1)
    {
      cout<<0<<'\n';continue;
    }
     // for(int i=0;i<=(int)s.size();i++)
    // {
    //   for(int j=0;j<=26;j++)
    //     for(int k=0;k<=26;k++)dp[i][j][k]=-1;
    // }
    for(int i=0;i<=26;i++)for(int j=0;j<=26;j++)dp[i][j].clear();
     int ans=2+dfs(2,26,26);
    ans=min(ans,1+dfs(2,26,s[1]-'a'));
    ans=min(ans,1+dfs(2,s[0]-'a',26));
    if(s[0]!=s[1])ans=min(ans,dfs(2,s[0]-'a',s[1]-'a'));
     cout<<ans<<'\n';
   }
  return 0;
}