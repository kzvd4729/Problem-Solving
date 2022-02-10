/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-31 22:02:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 327                                        memory_used (MB): 20.8                            
*  problem: https://vjudge.net/problem/HDU-6357
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int n,fr[N+2][12],bk[N+2][12],aa[N+2],dp[N+2][12],sml;
string s;int fnl[N+2][12];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t;cin>>t;
  while(t--)
  {
    cin>>n>>s;
    // for(int i=0;i<n;i++)
    // {
    //   char c='0'+rand()%10;
    //   s.push_back(c);
    // }
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
    int ans=0,ii=-1,jj=-1,kk=-1;

    for(int sml=0;sml<10;sml++)
    {
      for(int big=sml;big<10;big++)
      {
        for(int j=sml;j<=big;j++)dp[n][j]=0;
        for(int i=n-1;i>=0;i--)
        {
          for(int j=sml;j<=big;j++)dp[i][j]=dp[i+1][j];
          dp[i][aa[i]]++;
          for(int j=sml+1;j<=big;j++)
            dp[i][j]=max(dp[i][j],dp[i][j-1]);

          for(int j=sml;j<=big;j++)
            dp[i][j]=max(dp[i][j],bk[i][big]);
          
          int now=0;if(i)now+=fr[i-1][sml];
          now+=dp[i][big];
          if(now>ans)ans=now,ii=i,jj=sml,kk=big;
        }
      }
    }
    cout<<ans<<" ";if(ii)ans-=fr[ii-1][jj];
    int f=0;
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
        f=1;
        cout<<ii+1<<" "<<i+1<<"\n";break;
      }
    }
    if(f==0)cout<<1<<" "<<1<<"\n";
  }
  return 0;
}