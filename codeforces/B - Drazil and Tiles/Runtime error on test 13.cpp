/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 21:41                        
*  solution_verdict: Runtime error on test 13                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 16000 KB                             
*  problem: https://codeforces.com/contest/516/problem/B
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
const int N=2e3;
int n,m,vs[N+2][N+2];
int con(int x,int y)
{
  return m*(x-1)+y;
}
pair<int,int>con(int x)
{
  int r=(x-1)/m+1;
  return {r,x-(r-1)*m};
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string s[N+2];vector<int>ad[N+2];
int com;
void dfs(int nd)
{
  com++;vs[con(nd).first][con(nd).second]=1;
  for(auto x:ad[nd])
    if(vs[con(x).first][con(x).second]==0)dfs(x);
}
set<int>dl[N+2];
void no()
{
  cout<<"Not unique"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="*"+s[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='*')continue;
      for(int k=0;k<4;k++)
      {
        int u=i+dx[k],v=j+dy[k];
        if(u>=1&&u<=n&&v>=1&&v<=m&&s[u][v]=='.')
        {
          //cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
          //cout<<con(i,j)<<" "<<con(u,v)<<endl;
          ad[con(i,j)].push_back(con(u,v));
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='*'||vs[i][j])continue;
      com=0;dfs(con(i,j));if(com%2)no();
    }
  }
  for(int i=1;i<=n*m;i++)
  {
    for(auto x:ad[i])dl[i].insert(x);
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='*')continue;
      st.insert({(int)ad[con(i,j)].size(),con(i,j)});
    }
  }
  while((int)st.size())
  {
    pair<int,int>p=*st.begin();
    if(p.first>1)no();//st.erase(p);
     int u=p.second,v=*dl[p.second].begin();
    int i=con(u).first,j=con(u).second,k=con(v).first,l=con(v).second;
    if(i==k)
    {
      if(j<l)s[i][j]='<',s[k][l]='>';
      else s[k][l]='<',s[i][j]='>';
    }
    else
    {
      if(i<k)s[i][j]='^',s[k][l]='v';
      else s[k][l]='^',s[i][j]='v';
    }
     st.erase({(int)dl[u].size(),u});
    for(auto x:dl[u])
    {
      st.erase({(int)dl[x].size(),x});
      dl[x].erase(u);
      if((int)dl[x].size())st.insert({(int)dl[x].size(),x});
    }
    dl[u].clear();
     st.erase({(int)dl[v].size(),v});
    for(auto x:dl[v])
    {
      st.erase({(int)dl[x].size(),x});
      dl[x].erase(v);
      if((int)dl[x].size())st.insert({(int)dl[x].size(),x});
    }
    dl[v].clear();
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cout<<s[i][j];
      cout<<endl;
  }
  return 0;
}