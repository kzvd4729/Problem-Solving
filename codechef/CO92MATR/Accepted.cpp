/****************************************************************************************
*  @author: kzvd4729                                         created: 18-03-2018 22:10:50                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/COOK92A/problems/CO92MATR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e9;
long t,n,m,mat[102][102],tmp[102][102],mx,f;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>mat[i][j];
        tmp[i][j]=mat[i][j];
        if(mat[i][j]==-1)mat[i][j]=1;
      }
    }
    for(int i=1;i<=n;i++)
    {
      mx=-1;
      for(int j=1;j<=m;j++)
      {
        mx=max(mx,mat[i][j]);
        if(tmp[i][j]==-1)mat[i][j]=mx;
      }
    }
    for(int j=1;j<=m;j++)
    {
      mx=-1;
      for(int i=1;i<=n;i++)
      {
        mx=max(mx,mat[i][j]);
        if(tmp[i][j]==-1)mat[i][j]=mx;
      }
    }
    f=0;
    for(int i=1;i<=n;i++)
    {
      mx=-1;
      for(int j=1;j<=m;j++)
      {
        mx=max(mx,mat[i][j]);
        if(mx>mat[i][j]||mat[i][j]<1||mat[i][j]>inf)f=1;
      }
    }
    for(int j=1;j<=m;j++)
    {
      mx=-1;
      for(int i=1;i<=n;i++)
      {
        mx=max(mx,mat[i][j]);
        if(mx>mat[i][j]||mat[i][j]<1||mat[i][j]>inf)f=1;
      }
    }
    if(f)cout<<-1<<endl;
    else
    {
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          cout<<mat[i][j]<<" ";
        }
        cout<<endl;
      }
    }
  }
  return 0;
}