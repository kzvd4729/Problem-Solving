/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2020 15:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 102600 KB                            
*  problem: https://codeforces.com/contest/1316/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n;
pair<int,int>mt[N+2][N+2];
char ans[N+2][N+2];
bool isValid(int i,int j)
{
  return (i>=1)&&(j>=1)&&(i<=n)&&(j<=n);
}
void no()
{
  cout<<"INVALID\n",exit(0);
}
void dfs(int i,int j,pair<int,int>p)
{
  //cout<<i<<" "<<j<<endl;
  int ii,jj;
   ii=i+1,jj=j;
  if(isValid(ii,jj)&&mt[ii][jj]==p)
  {
    if(ans[ii][jj]=='0'){
    ans[ii][jj]='U';
    dfs(ii,jj,p);}
  }
   ii=i-1,jj=j;
  if(isValid(ii,jj)&&mt[ii][jj]==p)
  {
    if(ans[ii][jj]=='0'){
    ans[ii][jj]='D';
    dfs(ii,jj,p);}
  }
   ii=i,jj=j+1;
  if(isValid(ii,jj)&&mt[ii][jj]==p)
  {
    if(ans[ii][jj]=='0'){
    ans[ii][jj]='L';
    dfs(ii,jj,p);}
  }
   ii=i,jj=j-1;
  if(isValid(ii,jj)&&mt[ii][jj]==p)
  {
    if(ans[ii][jj]=='0'){
    ans[ii][jj]='R';
    dfs(ii,jj,p);}
  }
}
void print()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<ans[i][j];
    }
    cout<<"\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>mt[i][j].first>>mt[i][j].second;
      ans[i][j]='0';
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==mt[i][j].first&&j==mt[i][j].second)
      {
        ans[i][j]='X';//cout<<i<<" ** "<<j<<endl;
        dfs(i,j,{i,j});//print();
        //exit(0);
      }
    }
  }
  //print();
  pair<int,int>p={-1,-1};
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mt[i][j]==p&&ans[i][j]=='0')
      {
        if(isValid(i,j+1)&&(mt[i][j+1]==p)&&ans[i][j]=='0')
        {
          ans[i][j]='R';ans[i][j+1]='L';
        }
        else if(isValid(i+1,j)&&(mt[i+1][j]==p)&&ans[i][j]=='0')
        {
          ans[i][j]='D';ans[i+1][j]='U';
        }
        else if(isValid(i,j+1)&&(mt[i][j+1]==p))
        {
          ans[i][j]='R';
        }
        else if(isValid(i+1,j)&&(mt[i+1][j]==p))
        {
          ans[i][j]='D';
        }
        else if(isValid(i,j-1)&&(mt[i][j-1]==p))
        {
          ans[i][j]='L';
        }
        else if(isValid(i-1,j)&&(mt[i-1][j]==p))
        {
          ans[i][j]='U';
        }
      }
    }
  }
  //print();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      if(ans[i][j]=='0')no();
  }
  cout<<"VALID\n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<ans[i][j];
    }
    cout<<"\n";
  }
  return 0;
}