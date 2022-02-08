/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2018 15:39:09                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.14 sec                                        memory_used: 15.3M                                
*  problem: https://www.codechef.com/OCT18A/problems/SURCHESS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int mat[N+2][N+2],qm1[N+2][N+2],qm2[N+2][N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1]-'0';
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      qm1[i][j]=qm1[i][j-1];qm2[i][j]=qm2[i][j-1];
      if((i+j)%2==0)
      {
        qm1[i][j]+=mat[i][j];
        qm2[i][j]+=(mat[i][j]^1);
      }
      else
      {
        qm1[i][j]+=(mat[i][j]^1);
        qm2[i][j]+=mat[i][j];
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      qm1[i][j]+=qm1[i-1][j];
      qm2[i][j]+=qm2[i-1][j];
    }
  }
  for(int k=1;k<=min(n,m);k++)
  {
    int mn=2e9;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int ii=i+k-1,jj=j+k-1;
        if(ii>n||jj>m)continue;
        int sm1=qm1[ii][jj]-qm1[ii][j-1]-qm1[i-1][jj]+qm1[i-1][j-1];
        int sm2=qm2[ii][jj]-qm2[ii][j-1]-qm2[i-1][jj]+qm2[i-1][j-1];
        mn=min(mn,min(sm1,sm2));
      }
    }
    aa[k]=mn;
  }
  int q;cin>>q;
  while(q--)
  {
    int x,ans;cin>>x;
    for(int i=1;i<=min(n,m);i++)
    {
      if(aa[i]<=x)ans=i;
    }
    cout<<ans<<endl;
  }
  return 0;
}