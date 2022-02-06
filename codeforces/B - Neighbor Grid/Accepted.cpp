/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 21:07                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1375/problem/B
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
const int N=3e2;
int a[N+2],n,m,mt[N+2][N+2],ans[N+2][N+2];
bool isV(int i,int j)
{
  return i>=1&&i<=n&&j>=1&&j<=m;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        ans[i][j]=isV(i-1,j)+isV(i+1,j)+isV(i,j+1)+isV(i,j-1);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>mt[i][j];
        if(mt[i][j]>ans[i][j])f=1;
      }
    }
    if(f)cout<<"NO\n";
    else 
    {
      cout<<"YES\n";
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          cout<<ans[i][j]<<" ";
        cout<<"\n";
      }
    }
  }
  return 0;
}