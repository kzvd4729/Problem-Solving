/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/23/2020 14:19                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1528 ms                                         memory_used: 16200 KB                             
*  problem: https://codeforces.com/contest/372/problem/B
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
const int N=40;
string s[N+2];
int ok[N+2][N+2][N+2][N+2];
bool ck(int a,int b,int c,int d)
{
  if(a<=c&&b<=d)return ok[a][b][c][d];
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];s[i]="#"+s[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      for(int k=i;k<=n;k++)
      {
        for(int l=j;l<=m;l++)
        {
          if(s[k][l]=='1')continue;
          ok[i][j][k][l]=ck(i,j,k-1,l)&ck(i,j,k,l-1);
          //if(ok[i][j][k][l])cout<<i<<" "<<j<<" --> "<<k<<" "<<l<<endl;
          //cnt[i][j][k][l]+=ok[i][j][k][l];
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      for(int k=i;k<=n;k++)
      {
        for(int l=j;l<=m;l++)
        {
          ok[i][j][k][l]+=ok[i][j][k-1][l];
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      for(int k=i;k<=n;k++)
      {
        for(int l=j;l<=m;l++)
        {
          ok[i][j][k][l]+=ok[i][j][k][l-1];
        }
      }
    }
  }
  while(q--)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    int ans=0;
    for(int i=a;i<=c;i++)
    {
      for(int j=b;j<=d;j++)
        ans+=ok[i][j][c][d];
    }
    cout<<ans<<"\n";
  }
  return 0;
}