/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/14/2020 16:38                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 51000 KB                             
*  problem: https://codeforces.com/contest/1335/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int tim,bg,cm,sz[N+2];
vector<vector<int> >v,l,q;
string s[N+2],c[N+2];
void cycle(int i,int j,int d,int cm)
{
  if(l[i][j])return ;
  l[i][j]=d,q[i][j]=cm;
  //cout<<i<<" "<<j<<" "<<d<<" "<<cm<<endl;
  if(s[i][j]=='R')cycle(i,j+1,d+1,cm);
  if(s[i][j]=='L')cycle(i,j-1,d+1,cm);
  if(s[i][j]=='D')cycle(i+1,j,d+1,cm);
  if(s[i][j]=='U')cycle(i-1,j,d+1,cm);
}
void dfs(int i,int j)
{
  if(v[i][j])
  {
    if(v[i][j]>=bg&&!l[i][j])
    {
      ++cm;sz[cm]=tim-v[i][j]+1;
      cycle(i,j,1,cm);
    }
    return ;
  }
  v[i][j]=++tim;
  if(s[i][j]=='R')dfs(i,j+1);
  if(s[i][j]=='L')dfs(i,j-1);
  if(s[i][j]=='D')dfs(i+1,j);
  if(s[i][j]=='U')dfs(i-1,j);
}
vector<vector<pair<int,int> > >pp;
pair<int,int>dds(int i,int j)
{
  if(pp[i][j].first!=-1)return pp[i][j];
  if(s[i][j]=='R')pp[i][j]=dds(i,j+1);
  if(s[i][j]=='L')pp[i][j]=dds(i,j-1);
  if(s[i][j]=='D')pp[i][j]=dds(i+1,j);
  if(s[i][j]=='U')pp[i][j]=dds(i-1,j);
  pp[i][j].first--;if(pp[i][j].first==0)pp[i][j].first=sz[pp[i][j].second];
  return pp[i][j];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;v.resize(n+2),l.resize(n+2),q.resize(n+2),pp.resize(n+2);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)
    {
      v[i].resize(m+2),l[i].resize(m+2),q[i].resize(m+2),pp[i].resize(m+2);
      cin>>s[i];
      for(int j=0;j<m;j++)v[i][j]=0,l[i][j]=0,q[i][j]=0;
    }
    tim=0,cm=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        bg=tim+1;
        if(!v[i][j])dfs(i,j);
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        pp[i][j]={-1,-1};
        if(l[i][j])pp[i][j]={l[i][j],q[i][j]};
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        dds(i,j);
    }
    set<pair<int,int> >st;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(c[i][j]=='0')st.insert({pp[i][j]});
      }
    }
    int a=0;
    for(int i=1;i<=cm;i++)a+=sz[i];
    cout<<a<<" "<<st.size()<<endl;
  }
  return 0;
}