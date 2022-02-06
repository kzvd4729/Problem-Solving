/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2020 22:11                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1466 ms                                         memory_used: 121800 KB                            
*  problem: https://codeforces.com/contest/1185/problem/G2
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6,mod=1e9+7;
int way[50+2][50+2][50+2][3+2];
int calWay(int a,int b,int c,int f)
{
  if(a==0&&b==0&&c==0)return 1;
  if(way[a][b][c][f]!=-1)return way[a][b][c][f];
  int ret=0;
  if(f!=1&&a)ret=(ret+1LL*a*calWay(a-1,b,c,1))%mod;
  if(f!=2&&b)ret=(ret+1LL*b*calWay(a,b-1,c,2))%mod;
  if(f!=3&&c)ret=(ret+1LL*c*calWay(a,b,c-1,3))%mod;
  return way[a][b][c][f]=ret;
}
int aa[N+2],ty[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(way,-1,sizeof way);
   int n,t;cin>>n>>t;int a=0,b=0,c=0;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;if(y==1)++a;
    if(y==2)++b;if(y==3)++c;
     aa[i]=x,ty[i]=y;
  }
  int dp[2][a+1][b+1][c+1][t+1];
  memset(dp,0,sizeof dp);dp[0][0][0][0][0]=1;
  for(int i=1;i<=n;i++)
  {
    int id=i%2;
    for(int j=0;j<=a;j++)
    {
      for(int k=0;k<=b;k++)
      {
        for(int l=0;l<=c;l++)
        {
          for(int tm=0;tm<=t;tm++)
          {
            dp[id][j][k][l][tm]=dp[id^1][j][k][l][tm];
            if(aa[i]>tm)continue;
             if(ty[i]==1&&j)
              dp[id][j][k][l][tm]=(dp[id][j][k][l][tm]+dp[id^1][j-1][k][l][tm-aa[i]])%mod;
            if(ty[i]==2&&k)
              dp[id][j][k][l][tm]=(dp[id][j][k][l][tm]+dp[id^1][j][k-1][l][tm-aa[i]])%mod;
            if(ty[i]==3&&l)
              dp[id][j][k][l][tm]=(dp[id][j][k][l][tm]+dp[id^1][j][k][l-1][tm-aa[i]])%mod;
          }
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<=a;i++)
  {
    for(int j=0;j<=b;j++)
    {
      for(int k=0;k<=c;k++)
      {
        //if(dp[n%2][i][j][k][t])cout<<i<<" "<<j<<" "<<k<<endl;
        ans=(ans+calWay(i,j,k,0)*1LL*dp[n%2][i][j][k][t])%mod;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}