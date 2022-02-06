/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 20:53                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 157000 KB                            
*  problem: https://codeforces.com/contest/516/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3,inf=1e9;
int dg[N+2][N+2],n,m,cn[N+2][N+2];
string s[N+2];pair<int,int>pp[N*N+2];
set<int>adj[N+2][N+2];
bool valid(int i,int j)
{
  if(i<0||j<0||i>=n||j>=m)return false;
  return s[i][j]=='.';
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cn[i][j]=++cnt;pp[cnt]={i,j};
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(s[i][j]=='*')continue;
      if(valid(i-1,j))adj[i][j].insert(cn[i-1][j]);
      if(valid(i+1,j))adj[i][j].insert(cn[i+1][j]);
      if(valid(i,j-1))adj[i][j].insert(cn[i][j-1]);
      if(valid(i,j+1))adj[i][j].insert(cn[i][j+1]);
    }
  }
  set<pair<int,int> >st;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      dg[i][j]=adj[i][j].size();
      if(dg[i][j])st.insert({dg[i][j],cn[i][j]});
    }
  }
  pair<int,int>p,v;
  while(st.size())
  {
    v=*st.begin();st.erase(v);
    if(v.first!=1)cout<<"Not unique\n",exit(0);
     int i=pp[v.second].first,j=pp[v.second].second;
    int sm=*adj[i][j].begin();p=pp[sm];
    int a=p.first,b=p.second;
    st.erase({dg[a][b],cn[a][b]});
     for(auto x:adj[a][b])
    {
      int c=pp[x].first,d=pp[x].second;if(c==i&&d==j)continue;
      st.erase({dg[c][d],cn[c][d]});adj[c][d].erase(cn[a][b]);dg[c][d]--;
      st.insert({dg[c][d],cn[c][d]});
    }
     adj[a][b].erase(cn[i][j]);
    if(a==i&&b>j)s[i][j]='<',s[a][b]='>';
    else if(a==i)s[i][j]='>',s[a][b]='<';
    else if(b==j&&a>i)s[i][j]='^',s[a][b]='v';
    else s[i][j]='v',s[a][b]='^';
    //cout<<st.size()<<endl;
  }
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(s[i][j]=='.')cout<<"Not unique\n",exit(0);
  for(int i=0;i<n;i++)cout<<s[i]<<'\n';
  return 0;
}