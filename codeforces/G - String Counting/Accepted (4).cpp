/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2021 14:18                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 6801 ms                                         memory_used: 24200 KB                             
*  problem: https://codeforces.com/contest/1487/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
  #pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int n;
int dp[2][400+2][400+2][4][4],dp2[2][400+2][3][3];
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int f1=0;f1<=3;f1++)for(int f2=0;f2<=3;f2++)dp[(n+1)%2][0][0][f1][f2]=1;
   for(int i=n;i>=1;i--)
  {
    for(int a=0;a<=400;a++)
    {
      for(int b=0;b<=400;b++)
      {
        for(int f1=0;f1<=3;f1++)
        {
          for(int f2=0;f2<=3;f2++)
          {
            int id=i%2;long ret=0;
            int rd=(id^1);
            if(f1==0)
            {
              ret+=24LL*dp[rd][a][b][f2][3];
              if(a)ret+=dp[rd][a-1][b][f2][1];
              if(b)ret+=dp[rd][a][b-1][f2][2];
            }
            else if(f1==1)
            {
              ret+=24LL*dp[rd][a][b][f2][3];
              if(b)ret+=dp[rd][a][b-1][f2][2];
            }
            else if(f1==2)
            {
              ret+=24LL*dp[rd][a][b][f2][3];
              if(a)ret+=dp[rd][a-1][b][f2][1];
            }
            else
            {
              ret+=23LL*dp[rd][a][b][f2][3];
              if(a)ret+=dp[rd][a-1][b][f2][1];
              if(b)ret+=dp[rd][a][b-1][f2][2];
            }
            ret%=mod;
            dp[id][a][b][f1][f2]=ret;
          }
        }
      }
    }
  }
    for(int f1=0;f1<=2;f1++)for(int f2=0;f2<=2;f2++)dp2[(n+1)%2][0][f1][f2]=1;
   for(int i=n;i>=1;i--)
  {
    for(int a=0;a<=400;a++)
    {
      for(int f1=0;f1<=2;f1++)
      {
        for(int f2=0;f2<=2;f2++)
        {
          int id=i%2;long ret=0;
          int rd=(id^1);
          if(f1==0)
          {
            ret+=25LL*dp2[rd][a][f2][2];
            if(a)ret+=dp2[rd][a-1][f2][1];
          }
          else if(f1==1)
          {
            ret+=25LL*dp2[rd][a][f2][2];
          }
          else
          {
            ret+=24LL*dp2[rd][a][f2][2];
            if(a)ret+=dp2[rd][a-1][f2][1];
          }
          ret%=mod;
          dp2[id][a][f1][f2]=ret;
        }
      }
    }
  }
   for(int i=1;i<=26;i++)cin>>a[i];
   long tt=26*26;
  for(int i=3;i<=n;i++)
    tt=(tt*25)%mod;
   //cout<<tt<<endl;
  //cout<<"*"<<dp2[1][200][0][0]<<endl;
   for(int i=1;i<=26;i++)
  {
    for(int ii=a[i]+1;ii<=400;ii++)
    {
      tt=(tt-dp2[1][ii][0][0]+mod)%mod;
    }
  }
   for(int i=1;i<=26;i++)
  {
    for(int j=i+1;j<=26;j++)
    {
      for(int ii=a[i]+1;ii<=400;ii++)
      {
        for(int jj=a[j]+1;jj<=400;jj++)
        {
          tt=(tt+dp[1][ii][jj][0][0]+mod)%mod;
        }
      }
    }
  }
  cout<<tt<<endl;
   return 0;
}