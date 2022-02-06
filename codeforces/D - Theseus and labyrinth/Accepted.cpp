/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2020 11:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 779 ms                                          memory_used: 25400 KB                             
*  problem: https://codeforces.com/contest/676/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int n,m,a,b,c,d,ds[N+2][N+2][4+2];
string s[N+2];
bool isV(int i,int j,int k,char c)
{
  if(k==1)
  {
    if(c=='L')c='D';
    else if(c=='D')c='R';
    else if(c=='R')c='U';
    else if(c=='U')c='L';
  }
  else if(k==2)
  {
    if(c=='L')c='R';
    else if(c=='D')c='U';
    else if(c=='R')c='L';
    else if(c=='U')c='D';
  }
  else if(k==3)
  {
    if(c=='L')c='U';
    else if(c=='D')c='L';
    else if(c=='R')c='D';
    else if(c=='U')c='R'; 
  }
  if(c=='L')return s[i][j]=='+'|s[i][j]=='-'|s[i][j]=='<'|s[i][j]=='R'|s[i][j]=='U'|s[i][j]=='D';
  if(c=='R')return s[i][j]=='+'|s[i][j]=='-'|s[i][j]=='>'|s[i][j]=='L'|s[i][j]=='U'|s[i][j]=='D';
  if(c=='U')return s[i][j]=='+'|s[i][j]=='|'|s[i][j]=='^'|s[i][j]=='L'|s[i][j]=='R'|s[i][j]=='D';
  if(c=='D')return s[i][j]=='+'|s[i][j]=='|'|s[i][j]=='v'|s[i][j]=='L'|s[i][j]=='R'|s[i][j]=='U';
}
bool go(int i,int j,int k,char c)
{
  if(c=='L')
  {
    if(j-1<1)return false;
    return isV(i,j,k,c)&isV(i,j-1,k,'R');
  } 
  else if(c=='R')
  {
    if(j+1>m)return false;
    return isV(i,j,k,c)&isV(i,j+1,k,'L');
  }
  else if(c=='U')
  {
    if(i-1<1)return false;
    return isV(i,j,k,c)&isV(i-1,j,k,'D');
  }
  else if(c=='D')
  {
    if(i+1>n)return false;
    return isV(i,j,k,c)&isV(i+1,j,k,'U');
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="#"+s[i];
  cin>>a>>b>>c>>d;
  memset(ds,60,sizeof ds);
   queue<vector<int> >q;ds[a][b][0]=0;
  q.push({a,b,0});
   while(q.size())
  {
    vector<int>v=q.front();q.pop();
     if(ds[v[0]][v[1]][v[2]]+1<ds[v[0]][v[1]][(v[2]+1)%4])
    {
      ds[v[0]][v[1]][(v[2]+1)%4]=ds[v[0]][v[1]][v[2]]+1;
      q.push({v[0],v[1],(v[2]+1)%4});
    }
    int i=v[0],j=v[1],k=v[2];
    if(go(i,j,k,'L')&&ds[i][j][k]+1<ds[i][j-1][k])
      ds[i][j-1][k]=ds[i][j][k]+1,q.push({i,j-1,k});
    if(go(i,j,k,'R')&&ds[i][j][k]+1<ds[i][j+1][k])
      ds[i][j+1][k]=ds[i][j][k]+1,q.push({i,j+1,k});
    if(go(i,j,k,'U')&&ds[i][j][k]+1<ds[i-1][j][k])
      ds[i-1][j][k]=ds[i][j][k]+1,q.push({i-1,j,k});
    if(go(i,j,k,'D')&&ds[i][j][k]+1<ds[i+1][j][k])
      ds[i+1][j][k]=ds[i][j][k]+1,q.push({i+1,j,k});
  }
  int mn=inf;
  for(int i=0;i<4;i++)mn=min(mn,ds[c][d][i]);
  if(mn==inf)mn=-1;cout<<mn<<endl;
  return 0;
}