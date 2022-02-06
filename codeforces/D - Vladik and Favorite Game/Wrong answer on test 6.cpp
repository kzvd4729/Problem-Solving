/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2020 20:46                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/811/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
string s[N+2];int f1=-1,f2=-1,n,m,vs[100+2][100+2],u,v;
void dfs(int i,int j)
{
  vs[i][j]=1;if(s[i][j]=='F')exit(0);
  if(i+1<n&&s[i+1][j]!='*'&&vs[i+1][j]==0)
  {
    if(f1==-1)
    {
      cout<<'D'<<endl;
      cin>>u>>v;u--,v--;
      if(u==i+1)f1=1;
      else 
      {
        cout<<'U'<<endl;
        cin>>u>>v;f1=0;
      }
    }
    else
    {
      if(f1)
      {
        cout<<'D'<<endl;cin>>u>>v;
      }
      else 
      {
        cout<<'U'<<endl;cin>>u>>v;
      }
    }
    dfs(i+1,j);
  }
  if(i-1>=0&&s[i-1][j]!='*'&&vs[i-1][j]==0)
  {
    if(f1==-1)assert(0);
    else
    {
      if(f1)
      {
        cout<<'U'<<endl;cin>>u>>v;
      }
      else 
      {
        cout<<'D'<<endl;cin>>u>>v;
      }
    }
    dfs(i-1,j);
  }
   if(j+1<m&&s[i][j+1]!='*'&&vs[i][j+1]==0)
  {
    if(f2==-1)
    {
      cout<<'R'<<endl;
      cin>>u>>v;u--,v--;
      if(v==j+1)f2=1;
      else 
      {
        cout<<'L'<<endl;
        cin>>u>>v;f2=0;
      }
    }
    else
    {
      if(f2)
      {
        cout<<'R'<<endl;cin>>u>>v;
      }
      else 
      {
        cout<<'L'<<endl;cin>>u>>v;
      }
    }
    dfs(i,j+1);
  }
  if(j-1>=0&&s[i][j-1]!='*'&&vs[i][j-1]==0)
  {
    if(f2==-1)assert(0);
    else
    {
      if(f2)
      {
        cout<<'L'<<endl;cin>>u>>v;
      }
      else 
      {
        cout<<'R'<<endl;cin>>u>>v;
      }
    }
    dfs(i,j-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
   dfs(0,0);
   return 0;
}