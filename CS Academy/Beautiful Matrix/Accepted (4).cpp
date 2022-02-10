/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 7 ms                                            memory_used: 644 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define log long long
using namespace std;
long n,m,now,sum,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  long mat[n+2][m+2],tmp[n+2][m+2];
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  memset(tmp,0,sizeof(tmp));
  for(long i=1;i<n;i++)
  {
    for(long j=1;j<m;j++)
    {
      tmp[i][j]++;
      tmp[i+1][j]++;
      tmp[i][j+1]++;
      tmp[i+1][j+1]++;
    }
  }
  sum=0;
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)
    {
      sum+=mat[i][j]*tmp[i][j];
    }
  }
  ans=sum;
  for(long i=1;i<=n;i++)
  {
    now=sum;
    for(long j=1;j<=m;j++)
    {
      now=now-mat[1][j]*tmp[1][j];
      now=now-mat[i][j]*tmp[i][j];
      now=now+mat[1][j]*tmp[i][j];
      now=now+mat[i][j]*tmp[1][j];
    }
    ans=max(ans,now);
  }
  for(long i=1;i<=n;i++)
  {
    now=sum;
    for(long j=1;j<=m;j++)
    {
      now=now-mat[n][j]*tmp[n][j];
      now=now-mat[i][j]*tmp[i][j];
      now=now+mat[n][j]*tmp[i][j];
      now=now+mat[i][j]*tmp[n][j];
    }
    ans=max(ans,now);
  }
  for(long j=1;j<=m;j++)
  {
    now=sum;
    for(long i=1;i<=n;i++)
    {
      now=now-mat[i][1]*tmp[i][1];
      now=now-mat[i][j]*tmp[i][j];
      now=now+mat[i][1]*tmp[i][j];
      now=now+mat[i][j]*tmp[i][1];
    }
    ans=max(ans,now);
  }
  for(long j=1;j<=m;j++)
  {
    now=sum;
    for(long i=1;i<=n;i++)
    {
      now=now-mat[i][n]*tmp[i][n];
      now=now-mat[i][j]*tmp[i][j];
      now=now+mat[i][n]*tmp[i][j];
      now=now+mat[i][j]*tmp[i][n];
    }
    ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}