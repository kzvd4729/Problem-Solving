/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2021 23:05                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 12100 KB                             
*  problem: https://codeforces.com/contest/1498/problem/D
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
const int R=1e5;
  int ans[N+2],dp[N+2],md[R+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)ans[i]=-1;
  int rm=m;
   dp[0]=1;
  for(int i=1;i<=n;i++)
  {
    int ty,y;long x;cin>>ty>>x>>y;
    if(ty==1)
    {
      int vl=(x+R-1)/R;
      memset(md,0,sizeof md);
      for(int j=0;j<=m;j++)tmp[j]=dp[j];
      md[0]++;
       for(int j=1;j<=m;j++)
      {
        long dl=j-1LL*vl*y-1;
        if(dl>=0 && dp[dl])md[dl%vl]--;
         if(dp[j])
        {
          md[j%vl]++;
        }
        else if(md[j%vl])
        {
          tmp[j]=1;
          ans[j]=i;rm--;
        }
      }
      for(int j=0;j<=m;j++)dp[j]=tmp[j];
    }
    else
    {
      for(int j=0;j<=m;j++)tmp[j]=dp[j];
      for(int j=1;j<=m;j++)
      {
        if(dp[j]==0)continue;
        long k=j;
         //cout<<k<<" ";
        while(y--)
        {
          k=(1LL*k*x+R-1)/R;
          //cout<<k<<" ";
          if(k>m)break;
           if(tmp[k]==0)
          {
            tmp[k]=1;ans[k]=i;
            rm--;if(rm==0)break;
          }
        }
        //cout<<endl;
      }
      for(int j=0;j<=m;j++)dp[j]=tmp[j];
    }
    if(rm==0)break;
    //for(int j=1;j<=m;j++)cout<<ans[j]<<" ";cout<<endl;
  }
  for(int i=1;i<=m;i++)cout<<ans[i]<<" ";cout<<endl;
   return 0;
}