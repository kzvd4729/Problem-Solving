/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2019 10:42:40                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/JAN19A/problems/DIFNEIGH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    int mat[n+2][m+2];memset(mat,0,sizeof(mat));
    mat[1][1]=1;int mx=0;
    vector<pair<int,int> >ord;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=min(i,m);j++)
      {
        ord.push_back({i-j+1,j});
      }
    }
    for(int i=2;i<=m;i++)
    {
      for(int j=i;j<=min(i+n-1,m);j++)
      {
        ord.push_back({n-j+i,j});
      }
    }
    if(ord.size()!=n*m)assert(0);
    for(auto x:ord)
    {
      int i=x.first,j=x.second;
      int ii=i-1,jj=j;vector<int>v;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(mat[ii][jj])v.push_back(mat[ii][jj]);
      }
      ii=i+1,jj=j;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(mat[ii][jj])v.push_back(mat[ii][jj]);
      }
      ii=i,jj=j+1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(mat[ii][jj])v.push_back(mat[ii][jj]);
      }
      ii=i,jj=j-1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(mat[ii][jj])v.push_back(mat[ii][jj]);
      }
      sort(v.begin(),v.end());
      ii=i-1,jj=j;int cnt=1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(!mat[ii][jj])
        {
          while(binary_search(v.begin(),v.end(),cnt))cnt++;
          mat[ii][jj]=cnt;cnt++;
        }
      }
      ii=i+1,jj=j;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(!mat[ii][jj])
        {
          while(binary_search(v.begin(),v.end(),cnt))cnt++;
          mat[ii][jj]=cnt;cnt++;
        }
      }
      ii=i,jj=j+1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(!mat[ii][jj])
        {
          while(binary_search(v.begin(),v.end(),cnt))cnt++;
          mat[ii][jj]=cnt;cnt++;
        }
      }
      ii=i,jj=j-1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
      {
        if(!mat[ii][jj])
        {
          while(binary_search(v.begin(),v.end(),cnt))cnt++;
          mat[ii][jj]=cnt;cnt++;
        }
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        mx=max(mx,mat[i][j]);
      }
    }
    cout<<mx<<"\n";
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(j==1)cout<<mat[i][j];
        else cout<<" "<<mat[i][j];
      }
      cout<<"\n";
    }
  }
  return 0;
}