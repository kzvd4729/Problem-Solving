/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 20:42                        
*  solution_verdict: Memory limit exceeded on test 18        language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/516/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3,inf=1e9;
int dg[N+2][N+2],n,m;
string s[N+2];
set<pair<int,int> >adj[N+2][N+2];
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
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(s[i][j]=='*')continue;
      if(valid(i-1,j))adj[i][j].insert({i-1,j});
      if(valid(i+1,j))adj[i][j].insert({i+1,j});
      if(valid(i,j-1))adj[i][j].insert({i,j-1});
      if(valid(i,j+1))adj[i][j].insert({i,j+1});
    }
  }
  set<vector<int> >st;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      dg[i][j]=adj[i][j].size();
      if(dg[i][j])st.insert({dg[i][j],i,j});
    }
  }
  vector<int>v;pair<int,int>p;
  while(st.size())
  {
    v=*st.begin();st.erase(v);
    if(v[0]!=1)cout<<"Not unique\n",exit(0);
     int i=v[1],j=v[2];
    p=*adj[i][j].begin();
    int a=p.first,b=p.second;
    st.erase({dg[a][b],a,b});
     for(auto x:adj[a][b])
    {
      int c=x.first,d=x.second;if(c==i&&d==j)continue;
      st.erase({dg[c][d],c,d});adj[c][d].erase({a,b});dg[c][d]--;
      st.insert({dg[c][d],c,d});
    }
     adj[a][b].erase({i,j});
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