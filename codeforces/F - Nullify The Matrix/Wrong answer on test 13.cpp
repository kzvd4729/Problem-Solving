/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2020 19:55                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1451/problem/F
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
const int N=1e2;
int n,a[N+2][N+2],vs[N+2][N+2];
void dfs(int a,int b)
{
  if(a>n||b>n||vs[a][b])return ;
  vs[a][b]=1;dfs(a+1,b);dfs(a,b+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],vs[i][j]=0;
    int x=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(vs[i][j])continue;
        x^=a[i][j];dfs(i,j);
      }
    }
    if(x)cout<<"Ashish"<<endl;else cout<<"Jeel"<<endl;
  }
  return 0;
}