/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/961/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int cnt[10][10],n,x,ans=1e9;
char mat[102][102];
string s;
void input(void)
{
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=n;j++)
    {
      mat[i][j]=s[j-1];
    }
  }
}
void cal(int id)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      x=(i+j)%2;
      if((int)(mat[i][j]-'0')!=x)cnt[id][0]++;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      x=(i+j)%2;
      if((int)(mat[i][j]-'0')==x)cnt[id][1]++;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
   for(int i=1;i<=4;i++)
  {
    input();
    cal(i);
  }
  ans=min(ans,cnt[1][0]+cnt[2][0]+cnt[3][1]+cnt[4][1]);
  ans=min(ans,cnt[1][0]+cnt[3][0]+cnt[2][1]+cnt[4][1]);
  ans=min(ans,cnt[1][0]+cnt[4][0]+cnt[2][1]+cnt[3][1]);
  ans=min(ans,cnt[2][0]+cnt[3][0]+cnt[1][1]+cnt[4][1]);
  ans=min(ans,cnt[2][0]+cnt[4][0]+cnt[1][1]+cnt[3][1]);
  ans=min(ans,cnt[3][0]+cnt[4][0]+cnt[1][1]+cnt[2][1]);
   cout<<ans<<endl;
  return 0;
}