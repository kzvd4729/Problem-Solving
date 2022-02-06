/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2020 21:36                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/gym/100803/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2],b[N+2],c[N+2],d[N+2],n;
bool goNorth(int x,int y)
{
  for(int i=1;i<=n;i++)
  {
    if((a[i]==c[i])&&(a[i]==x)&&(y>=min(b[i],d[i]))&&(y+1<=max(b[i],d[i])))
    {
      y++;return true;
    }
  }
  return false;
}
bool goSouth(int x,int y)
{
  for(int i=1;i<=n;i++)
  {
    if((a[i]==c[i])&&(a[i]==x)&&(y-1>=min(b[i],d[i]))&&(y<=max(b[i],d[i])))
    {
      y--;return true;
    }
  }
  return false;
}
bool goEast(int x,int y)
{
  for(int i=1;i<=n;i++)
  {
    if((b[i]==d[i])&&(b[i]==y)&&(x>=min(a[i],c[i]))&&(x+1<=max(a[i],c[i])))
    {
      x++;return true;
    }
  }
  return false;
}
bool goWest(int x,int y)
{
  for(int i=1;i<=n;i++)
  {
    if((b[i]==d[i])&&(b[i]==y)&&(x-1>=min(a[i],c[i]))&&(x<=max(a[i],c[i])))
    {
      x--;return true;
    }
  }
  return false;
}
vector<pair<int,int> >u;
void dfs(int d,int x,int y,int l)
{
  //cout<<x<<" "<<y<<" "<<d<<endl;
  if(d==0)
  {
    //cout<<x<<" "<<y<<endl;
    u.push_back({x,y});return ;
  }
  if(l!=2&&goNorth(x,y))dfs(d-1,x,y+1,1);
  if(l!=1&&goSouth(x,y))dfs(d-1,x,y-1,2);
  if(l!=4&&goEast(x,y))dfs(d-1,x+1,y,3);
  if(l!=3&&goWest(x,y))dfs(d-1,x-1,y,4);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x,y,t;cin>>n>>x>>y>>t;
  for(int i=1;i<=n;i++)
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  //cout<<goEast(9,0)<<endl;
  vector<pair<int,int> >v;v.push_back({x,y});
  for(int i=1;i<=t;i++)
  {
    int d;char c;cin>>d>>c;
    u.clear();
    for(auto x:v)
    {
      if(c=='N')dfs(d,x.first,x.second,1);
      if(c=='S')dfs(d,x.first,x.second,2);
      if(c=='E')dfs(d,x.first,x.second,3);
      if(c=='W')dfs(d,x.first,x.second,4);
    }
    v=u;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}