/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/05/2019 18:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 23700 KB                             
*  problem: https://codeforces.com/contest/148/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#define long long long
using namespace std;
const int N=1e3;
int vis[N+2][N+2][2];
double dp[N+2][N+2][2];
double dfs(int w,int b,int f)
{
  if(!(w+b))return 0;
  if(!w)return f;
  if(!b)return !f;
   if(vis[w][b][f])return dp[w][b][f];
  double tt=w+b,now=0;
  double ww=1.0*w/tt,bb=1.0*b/tt;
  if(!f)now+=ww+bb*dfs(w,b-1,1);
  else
  {
    now+=ww;
    now+=bb*w/(tt-1)*(1-dfs(w-1,b-1,0));
    if(b>=2)now+=bb*(b-1)/(tt-1)*(1-dfs(w,b-2,0));
    now=1-now;
  }
  vis[w][b][f]=1;
  return dp[w][b][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int w,b;cin>>w>>b;
  cout<<setprecision(10)<<fixed<<dfs(w,b,0)<<endl;
  return 0;
}