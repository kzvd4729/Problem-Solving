/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-31 19:46:43                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-6357
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int n,fr[N+2][12],bk[N+2][12],aa[N+2],dp[N+2][12][12],sml;
string s;int fnl[N+2][12];
inline int dfs(int i,int bg,int tbg)
{
  if(i==n)return 0;
  if(dp[i][bg][tbg]!=-1)return dp[i][bg][tbg];
  int ret=bk[i][bg];
  ret=max(ret,dfs(i+1,bg,tbg));
  if(aa[i]<=tbg&&aa[i]>=sml)
    ret=max(ret,1+dfs(i+1,bg,aa[i]));
  return dp[i][bg][tbg]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
    {
      char c='0'+rand()%10;
      s.push_back(c);
    }
    for(int i=0;i<n;i++)aa[i]=s[i]-'0';
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=10;j++)
        fr[i][j]=0,bk[i][j]=0,fnl[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
      if(i)
      {
        for(int j=0;j<10;j++)
          fr[i][j]=fr[i-1][j];
      }
      fr[i][s[i]-'0']++;
      for(int j=1;j<10;j++)
        fr[i][j]=max(fr[i][j],fr[i][j-1]);
    }
    for(int i=n-1;i>=0;i--)
    {
      if(i<n-1)
      {
        for(int j=0;j<10;j++)
          bk[i][j]=bk[i+1][j];
      }
      bk[i][s[i]-'0']++;
      for(int j=8;j>=0;j--)
        bk[i][j]=max(bk[i][j],bk[i][j+1]);
    }
    int ans=0,ii,jj,kk;
    for(int j=0;j<=9;j++)
    {
      sml=j;
      for(int a=0;a<=n;a++)
      {
        for(int b=0;b<=10;b++)
          for(int c=0;c<=10;c++)dp[a][b][c]=-1;
      }
      for(int k=j;k<=9;k++)
      {
        for(int i=0;i<n;i++)
        {
          int now=0;if(i)now+=fr[i-1][j];
          now+=dfs(i,k,k);
          if(now>ans)
          {
            ans=now,ii=i,jj=j,kk=k;
          }
        }
      }
    }
    cout<<ans<<" ";if(ii)ans-=fr[ii-1][jj];
    for(int i=ii;i<n;i++)
    {
      if(i)
      {
        for(int j=0;j<=kk;j++)
          fnl[i][j]=fnl[i-1][j];
      }
      fnl[i][aa[i]]++;
      for(int j=kk-1;j>=0;j--)
        fnl[i][j]=max(fnl[i][j],fnl[i][j+1]);
      if(fnl[i][jj]+bk[i+1][kk]==ans)
      {
        cout<<ii+1<<" "<<i+1<<"\n";break;
      }
    }
  }
  return 0;
}