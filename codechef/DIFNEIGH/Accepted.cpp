/****************************************************************************************
*  @author: kzvd4729                                         created: 12-01-2019 18:18:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JAN19A/problems/DIFNEIGH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    int mn=min(n,m),mx=max(n,m);
    int mat[n+2][m+2];
    if(mn<=1&&mx<=2)
    {
      cout<<1<<endl;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          mat[i][j]=1;
        }
      }
    }
    else if(mn<=1)
    {
      cout<<2<<endl;
      if(n==1)
      {
        int bg=1;
        for(int j=1;j<=m;j++)
        {
          mat[1][j]=bg++;
          if(mat[1][j]==2)mat[1][j]=1;
          if(mat[1][j]==3)mat[1][j]=2;
          if(mat[1][j]==4)mat[1][j]=2;
          if(bg==5)bg=1;
        }
      }
      else
      {
        int bg=1;
        for(int i=1;i<=n;i++)
        {
          mat[i][1]=bg++;
          if(mat[i][1]==2)mat[i][1]=1;
          if(mat[i][1]==3)mat[i][1]=2;
          if(mat[i][1]==4)mat[i][1]=2;
          if(bg==5)bg=1;
        }
      }
    }
    else if(mn==2&&mx==2)
    {
      cout<<2<<endl;
      for(int i=1;i<=n;i++)
      {
        int bg=1;
        for(int j=1;j<=m;j++)
        {
          mat[i][j]=bg++;
          if(bg==3)bg=1;
        }
      }
    }
    else if(mn<=2)
    {
      cout<<3<<endl;
      if(n<=2)
      {
        for(int i=1;i<=n;i++)
        {
          int bg=1;
          for(int j=1;j<=m;j++)
          {
            mat[i][j]=bg++;
            if(bg==4)bg=1;
          }
        }
      }
      else
      {
        for(int j=1;j<=m;j++)
        {
          int bg=1;
          for(int i=1;i<=n;i++)
          {
            mat[i][j]=bg++;
            if(bg==4)bg=1;
          }
        }
      }
    }
    else
    {
      cout<<4<<endl;
      for(int i=1;i<=n;i++)
      {
        int bg;
        if(i%4==1||i%4==2)bg=1;
        else bg=3;
        for(int j=1;j<=m;j++)
        {
          mat[i][j]=bg++;
          if(bg==5)bg=1;
        }
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}