/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2018 20:37:35                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/LTIME62A/problems/FRCPRT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int t,n,m;
char mat[N+2][N+2];
string s;
void exc(char c)
{
  if(c=='L'||c=='R')
  {
    for(int i=1;i<=n;i++)
    {
      int cnt=0;
      for(int j=1;j<=m;j++)
      {
        if(mat[i][j]=='1')cnt++;
      }
      if(c=='L')
      {
        for(int j=1;j<=m;j++)
        {
          if(cnt==0)mat[i][j]='0';
          else mat[i][j]='1',cnt--;
        }
      }
      else
      {
        for(int j=m;j>=1;j--)
        {
          if(cnt==0)mat[i][j]='0';
          else mat[i][j]='1',cnt--;
        }
      }
    }
  }
  else
  {
    for(int j=1;j<=m;j++)
    {
      int cnt=0;
      for(int i=1;i<=n;i++)
      {
        if(mat[i][j]=='1')cnt++;
      }
      if(c=='U')
      {
        for(int i=1;i<=n;i++)
        {
          if(cnt==0)mat[i][j]='0';
          else mat[i][j]='1',cnt--;
        }
      }
      else
      {
        for(int i=n;i>=1;i--)
        {
          if(cnt==0)mat[i][j]='0';
          else mat[i][j]='1',cnt--;
        }
      }
    }
  }
}
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
      cin>>s;
      for(int j=1;j<=m;j++)
        mat[i][j]=s[j-1];
    }
    cin>>s;
    int f1=0,f2=0;
    for(auto x:s)
    {
      if(x=='L'||x=='R'&&f1==0)
      {
        exc(x);
        f1=1;
      }
      else if(x=='U'||x=='D'&&f2==0)
      {
        exc(x);
        f2=1;
      }
    }
    int po;
    f1=0,f2=0;
    for(int i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='L'||s[i]=='R')
      {
        if(f2)
        {
          exc(s[i]);
          exc(s[po]);
          break;
        }
        if(f1==0)
        {
          f1=1;
          po=i;
        }
      }
      else
      {
        if(f1)
        {
          exc(s[i]);
          exc(s[po]);
          break;
        }
        if(f2==0)
        {
          f2=1;
          po=i;
        }
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cout<<mat[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}