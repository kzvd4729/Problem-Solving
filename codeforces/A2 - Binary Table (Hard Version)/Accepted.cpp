/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 19:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1439/problem/A2
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int a[100+2][100+2];
vector<vector<int> >ans;
void cal3(int x1,int x2,int y1,int y2)
{
  vector<int>v;
  for(int i=x1;i<=x2;i++)
  {
    for(int j=y1;j<=y2;j++)
    {
      if(a[i][j])v.push_back(i),v.push_back(j),a[i][j]=0;
    }
  }
  ans.push_back(v);
}
void cal2(int x1,int x2,int y1,int y2)
{
  vector<int>v;int x,y;
  for(int i=x1;i<=x2;i++)
  {
    for(int j=y1;j<=y2;j++)
    {
      if(a[i][j]==0)v.push_back(i),v.push_back(j),a[i][j]=1;
      else x=i,y=j;
    }
  }
  v.push_back(x);v.push_back(y);a[x][y]=0;
  ans.push_back(v);cal3(x1,x2,y1,y2);
}
void cal1(int x1,int x2,int y1,int y2)
{
  vector<int>v;int x,y,cnt=2;
  for(int i=x1;i<=x2;i++)
  {
    for(int j=y1;j<=y2;j++)
    {
      if(a[i][j]==0&&cnt)v.push_back(i),v.push_back(j),a[i][j]=1,cnt--;
      else if(a[i][j]==1)x=i,y=j;
    }
  }
  v.push_back(x);v.push_back(y);a[x][y]=0;
  ans.push_back(v);cal2(x1,x2,y1,y2);
}
void cal4(int x1,int x2,int y1,int y2)
{
  vector<int>v;int x,y,cnt=3;
  for(int i=x1;i<=x2;i++)
  {
    for(int j=y1;j<=y2;j++)
    {
      if(a[i][j]&&cnt)v.push_back(i),v.push_back(j),a[i][j]=0,cnt--;
    }
  }
  ans.push_back(v);cal1(x1,x2,y1,y2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    ans.clear();
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      for(int j=1;j<=m;j++)a[i][j]=(s[j-1]=='1');
    }
    for(int i=1;i<=n-2;i++)
    {
      for(int j=1;j<=m;j+=2)
      {
        if(j==m)
        {
          if(a[i][j])
          {
            a[i][j]=0;
            a[i+1][j-1]^=1;a[i+1][j]^=1;
            ans.push_back({i,j,i+1,j-1,i+1,j});
          }
        }
        else
        {
          if(a[i][j]&&a[i][j+1])
          {
            a[i][j]^=1,a[i][j+1]^=1;
            a[i+1][j]^=1;
            ans.push_back({i,j,i,j+1,i+1,j});
          }
          else if(a[i][j])
          {
            a[i][j]^=1,a[i+1][j]^=1;
            a[i+1][j+1]^=1;
            ans.push_back({i,j,i+1,j,i+1,j+1});
          }
          else if(a[i][j+1])
          {
            a[i][j+1]^=1,a[i+1][j]^=1;
            a[i+1][j+1]^=1;
            ans.push_back({i,j+1,i+1,j,i+1,j+1});
          }
        }
      }
    }
    for(int j=1;j<=m-2;j++)
    {
      if(a[n][j]&&a[n-1][j])
      {
        a[n][j]^=1,a[n-1][j]^=1;
        a[n][j+1]^=1;
        ans.push_back({n,j,n-1,j,n,j+1});
      }
      else if(a[n][j])
      {
        a[n][j]^=1;a[n][j+1]^=1;
        a[n-1][j+1]^=1;
        ans.push_back({n,j,n,j+1,n-1,j+1});
      }
      else if(a[n-1][j])
      {
        a[n-1][j]^=1;a[n][j+1]^=1;
        a[n-1][j+1]^=1;
        ans.push_back({n-1,j,n,j+1,n-1,j+1});
      }
    }
    int cnt=0;
    for(int i=n-1;i<=n;i++)
    {
      for(int j=m-1;j<=m;j++)
        cnt+=a[i][j];
    }
    if(cnt==1)cal1(n-1,n,m-1,m);
    else if(cnt==2)cal2(n-1,n,m-1,m);
    else if(cnt==3)cal3(n-1,n,m-1,m);
    else if(cnt==4)cal4(n-1,n,m-1,m);
     cout<<ans.size()<<endl;
    for(auto x:ans)
    {
      for(int i=0;i<(int)x.size();i++)cout<<x[i]<<" ";
        cout<<endl;
    }
  }
  return 0;
}