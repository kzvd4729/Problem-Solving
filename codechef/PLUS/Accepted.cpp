/****************************************************************************************
*  @author: kzvd4729                                         created: 26-05-2018 21:39:13                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.27 sec                                        memory_used: 84.6M                                
*  problem: https://www.codechef.com/LTIME60A/problems/PLUS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e15;
const int N=1e3;
long t,mat[N+2][N+2],n,m;
long rfqm[N+2][N+2],cfqm[N+2][N+2],rbqm[N+2][N+2],cbqm[N+2][N+2];
long rfmx[N+2][N+2],cfmx[N+2][N+2],rbmx[N+2][N+2],cbmx[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    memset(mat,0,sizeof(mat));
    memset(rfqm,0,sizeof(rfqm));
    memset(cfqm,0,sizeof(cfqm));
    memset(rbqm,0,sizeof(rbqm));
    memset(cbqm,0,sizeof(cbqm));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>mat[i][j];
    for(int i=0;i<=n+1;i++)
    {
      for(int j=0;j<=m+1;j++)
      {
        rfmx[i][j]=-inf;
        rbmx[i][j]=-inf;
        cfmx[i][j]=-inf;
        cbmx[i][j]=-inf;
      }
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        rfqm[i][j]=rfqm[i][j-1]+mat[i][j];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cfqm[i][j]=cfqm[i-1][j]+mat[i][j];
    for(int i=n;i>=1;i--)
      for(int j=m;j>=1;j--)
        rbqm[i][j]=rbqm[i][j+1]+mat[i][j];
    for(int i=n;i>=1;i--)
      for(int j=m;j>=1;j--)
        cbqm[i][j]=cbqm[i+1][j]+mat[i][j];
    for(int i=n;i>=1;i--)
      for(int j=m;j>=1;j--)
        rfmx[i][j]=max(rfqm[i][j],rfmx[i][j+1]);
    for(int i=n;i>=1;i--)
      for(int j=m;j>=1;j--)
        cfmx[i][j]=max(cfqm[i][j],cfmx[i+1][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        rbmx[i][j]=max(rbqm[i][j],rbmx[i][j-1]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cbmx[i][j]=max(cbqm[i][j],cbmx[i-1][j]);
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//      for(int j=1;j<=m;j++)
//      {
//        cout<<cbmx[i][j]<<" ";
//      }
//      cout<<endl;
//    }
    long ans=-1e15;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(i==1||j==1||i==n||j==m)continue;
        long here=rfmx[i][j+1]-rfqm[i][j]+cfmx[i+1][j]-cfqm[i][j];
        here+=rbmx[i][j-1]-rbqm[i][j]+cbmx[i-1][j]-cbqm[i][j];
        ans=max(ans,here+mat[i][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}