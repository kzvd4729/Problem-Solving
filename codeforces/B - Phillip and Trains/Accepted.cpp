/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2020 15:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/585/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#define long long long
using namespace std;
const int N=1e6;
int n,k,dp[3+2][100+2];
string a[N+2];vector<pair<int,int> >v[3+2];
void move(int f)
{
  for(int i=0;i<3;i++)
  {
    for(auto &x:v[i])
      x.first-=f*2,x.second-=f*2;
  }
}
bool isOk(int i,int j)
{
  if(i<0||i>2)return false;
  for(auto x:v[i])
  {
    //if(i==2&&j==3)cout<<j<<" "<<x.first<<" "<<x.second<<endl;
    if(j>=x.first&&j<=x.second)return false;
  }
  return true;
}
bool dfs(int i,int j)
{
  //cout<<i<<" "<<j<<endl;
  if(dp[i][j]!=-1)return dp[i][j];
  if(!isOk(i,j))return dp[i][j]=false;
  if(j==n-1)return dp[i][j]=true;
  int ret=false;
  if(isOk(i,j+1))
  {
    move(1);ret=dfs(i,j+1);
    move(-1);
  }
  if(isOk(i,j+1)&&isOk(i-1,j+1))
  {
    move(1);ret|=dfs(i-1,j+1);
    move(-1);
  }
  if(isOk(i,j+1)&&isOk(i+1,j+1))
  {
    move(1);ret|=dfs(i+1,j+1);
    move(-1);
  }
  return dp[i][j]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(int i=0;i<3;i++)cin>>a[i],v[i].clear();
     for(int i=0;i<3;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(a[i][j]=='.'||a[i][j]=='s')continue;
        int lt=j;
        while(j<n&&a[i][j]!='.')j++;
        j--;v[i].push_back({lt,j});
      }
    }
    int ret=0;memset(dp,-1,sizeof(dp));
    if(a[0][0]=='s')ret=dfs(0,0);
    if(a[1][0]=='s')ret=dfs(1,0);
    if(a[2][0]=='s')ret=dfs(2,0);
    if(ret)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}