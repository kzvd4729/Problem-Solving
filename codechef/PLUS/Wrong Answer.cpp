/****************************************************************************************
*  @author: kzvd4729                                         created: 26-05-2018 20:44:02                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
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
        here=0;
        lm=min(n-i,i-1);
        lm=min(lm,min(m-j,j-1));
        for(int k=1;k<=lm;k++)
        {
          here+=mat[i+k][j]+mat[i-k][j]+mat[i][j+k]+mat[i][j-k];
          ans=max(ans,here+mat[i][j]);
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}