/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-23 20:39:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1051
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,good,bad,vis[55][6][6];
string s;
int check(char c)
{
  if(c=='A')return 0;
  if(c=='E')return 0;
  if(c=='I')return 0;
  if(c=='O')return 0;
  if(c=='U')return 0;
  return 1;
}
void dfs(int i,int c,int v)
{
  if(c==5||v==3)
  {
    bad=1;
    return ;
  }
  if(i==s.size())
  {
    good=1;
    return ;
  }
  if(vis[i][c][v])return ;
  vis[i][c][v]=1;
  if(s[i]=='?')
  {
    dfs(i+1,c+1,0);
    dfs(i+1,0,v+1);
  }
  int x=check(s[i]);
  if(x==0)dfs(i+1,0,v+1);
  else dfs(i+1,c+1,0);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    good=0,bad=0;
    memset(vis,0,sizeof(vis));
    dfs(0,0,0);

    if(good&&bad)
      cout<<"Case "<<++tc<<": MIXED"<<endl;
    else if(good)
      cout<<"Case "<<++tc<<": GOOD"<<endl;
    else
      cout<<"Case "<<++tc<<": BAD"<<endl;
  }
  return 0;
}