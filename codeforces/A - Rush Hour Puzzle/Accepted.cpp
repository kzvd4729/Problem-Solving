/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 18:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/gym/102460/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
map<vector<vector<int> >,int>mp;
void mv(vector<vector<int> >&x,vector<vector<int> >&u,vector<vector<int> >&v,int k)
{
  //cout<<"enter"<<endl;
  vector<pair<int,int> >p;
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
      if(x[i][j]==k)p.push_back({i,j});
  }
  if(p.size()==0)
  {
    //cout<<"exit"<<endl;
    return ;
  }
  sort(p.begin(),p.end());int hr=0;
  if(p[1].first==p[0].first)hr=1;
   if(hr)
  {
    int r=p.back().first,c=p.back().second+1;
    if(c<6&&x[r][c]==0)
    {
      u=x;swap(u[r][c],u[r][p[0].second]);
      //cout<<u[r][c]<<" "<<u[r][p[0].second]<<endl;
    }
    c=p[0].second-1;
    if(c>=0&&x[r][c]==0)
    {
      v=x;swap(v[r][c],v[r][p.back().second]);
      //cout<<v[r][c]<<" "<<v[r][p.back().second]<<endl;
    }
  }
  else
  {
    int r=p.back().first+1,c=p.back().second;
    if(r<6&&x[r][c]==0)
    {
      //cout<<"here"<<endl;
      u=x;swap(u[r][c],u[p[0].first][c]);
    }
    r=p[0].first-1;
    if(r>=0&&x[r][c]==0)
    {
      //cout<<"here"<<endl;
      v=x;swap(v[r][c],v[p.back().first][c]);
    } 
  }
  //cout<<"exit"<<endl;
}
void print(vector<vector<int> >v)
{
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<vector<int> >v(6);int mx=0;
  for(int i=0;i<6;i++)
  {
    v[i].resize(6);
    for(int j=0;j<6;j++)
    {
      cin>>v[i][j];
      mx=max(mx,v[i][j]);
    }
  }
  mp[v]=2;queue<vector<vector<int> > >q;q.push(v);
  //print(v);
  while(q.size())
  {
    vector<vector<int> >u,v,x=q.front();q.pop();
    if(mp[x]>10)continue;
    //print(x);
    if(x[2][5]==1)cout<<mp[x]<<endl,exit(0);
     for(int i=1;i<=mx;i++)
    {
      u.clear();v.clear();
      mv(x,u,v,i);
       if(u.size()&&(!mp.count(u)))
      {
        q.push(u);mp[u]=mp[x]+1;
        //print(u);
      }
      if(v.size()&&(!mp.count(v)))
      {
        q.push(v);mp[v]=mp[x]+1;
        //print(v);
      }
    }
    //exit(0);
  }
  cout<<-1<<endl;
  return 0;
}