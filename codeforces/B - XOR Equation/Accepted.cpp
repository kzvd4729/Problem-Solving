/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/634/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>a,b;
long dp[60+2][2];
long dfs(int i,int c)
{
  if(i==60)return !c;
  if(dp[i][c]!=-1)return dp[i][c];
  long ret=0;
  if(b[i])
  {
    int nw=1,nc=0;if(c)nw=0,nc=1;
    if(nw==a[i])ret+=2*dfs(i+1,nc);
  }
  else
  {
    //double zr;
    int nw=0,nc=0;if(c)nw=1,nc=0;
    if(nw==a[i])ret+=dfs(i+1,nc);
     //double one
    nw=0,nc=1;if(c)nw=1,nc=1;
    if(nw==a[i])ret+=dfs(i+1,nc);    
  }
  return dp[i][c]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long s,x;cin>>s>>x;
  for(long i=0;i<60;i++)a.push_back((bool)(s&(1LL<<i)));
  for(long i=0;i<60;i++)b.push_back((bool)(x&(1LL<<i)));
   memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)-(s==x)*2<<endl;
    return 0;
}