/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 17:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1434 ms                                         memory_used: 38800 KB                             
*  problem: https://codeforces.com/contest/1072/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
const int inf=1e9;
int dis[N+2][N+2];
char mat[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
      mat[i][j]=s[j-1];
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      dis[i][j]=inf;
  int ds=1;
  if(mat[1][1]=='a')ds=0;
  set<pair<int,pair<int,int> > >st;st.insert({ds,{1,1}});
   int mx=0;
  while(st.size())
  {
    pair<int,pair<int,int> >p=*st.begin();
    st.erase(p);dis[p.second.first][p.second.second]=p.first;
     if(dis[p.second.first][p.second.second]==k)
      mx=max(mx,p.second.first+p.second.second);
     if(p.second.first+1<=n&&dis[p.second.first+1][p.second.second]==inf)
    {
      if(mat[p.second.first+1][p.second.second]=='a')
        dis[p.second.first+1][p.second.second]=p.first;
      else dis[p.second.first+1][p.second.second]=p.first+1;
      st.insert({dis[p.second.first+1][p.second.second],{p.second.first+1,p.second.second}});
    }
    if(p.second.second+1<=n&&dis[p.second.first][p.second.second+1]==inf)
    {
      if(mat[p.second.first][p.second.second+1]=='a')
        dis[p.second.first][p.second.second+1]=p.first;
      else dis[p.second.first][p.second.second+1]=p.first+1;
      st.insert({dis[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
    }
  }
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    if(i<mx)
    {
      if(dis[i][mx-i]==k)
        v.push_back({i,mx-i});
    }
  }
  if(dis[n][n]<=k)
  {
    for(int i=1;i<=2*n-1;i++)
      cout<<'a';
    cout<<endl;
    exit(0);
  }
  mx--;
  while(mx>0)
  {
    cout<<'a';mx--;
  }
  queue<pair<int,int> >q1,q2;
  for(auto x:v)
  {
    if(x.first+1<=n)
      q1.push({x.first+1,x.second});
    if(x.second+1<=n)
      q1.push({x.first,x.second+1});
  }
  if(q1.size()==0)q1.push({1,1});
  while(true)
  {
    q2=q1;char mn='z';
    while(q1.size())
    {
      pair<int,int>p=q1.front();q1.pop();
      mn=min(mn,mat[p.first][p.second]);
    }
    while(q2.size())
    {
      pair<int,int>p=q2.front();q2.pop();
      if(mat[p.first][p.second]==mn)
      {
        q1.push(p);
      }
    }
    cout<<mn;
    set<pair<int,int> >st;
    while(q1.size())
    {
      pair<int,int>p=q1.front();q1.pop();
      if(p.first+1<=n)
        st.insert({p.first+1,p.second});
      if(p.second+1<=n)
        st.insert({p.first,p.second+1});
    }
    while(st.size())
    {
      pair<int,int>p=*st.begin();
      q1.push(p);st.erase(p);
    }
    if(q1.size()==0)break;
  }
  cout<<endl;
  return 0;
}