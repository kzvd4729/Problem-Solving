/****************************************************************************************
*  @author: kzvd4729                                         created: 26-05-2018 20:55:53                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/LTIME60A/problems/PLUS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,ans,mat[1002][1002],n,m,here,lm;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>mat[i][j];
    ans=-1e12;
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=m;j++)
      {
        long mx1=-1e12,mx2=-1e12,mx3=-1e12,mx4=-1e12;
        here=0;
        for(int k=1;k<=n;k++)
        {
          if(i+k>n)break;
          here+=mat[i+k][j];
          mx1=max(mx1,here);
        }
        here=0;
        for(int k=1;k<=n;k++)
        {
          if(i-k<1)break;
          here+=mat[i-k][j];
          mx2=max(mx2,here);
        }
        here=0;
        for(int k=1;k<=m;k++)
        {
          if(j+k>m)break;
          here+=mat[i][j+k];
          mx3=max(mx3,here);
        }
        here=0;
        for(int k=1;k<=m;k++)
        {
          if(j-k<1)break;
          here+=mat[i][j-k];
          mx4=max(mx4,here);
        }
        ans=max(ans,mat[i][j]+mx1+mx2+mx3+mx4);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}