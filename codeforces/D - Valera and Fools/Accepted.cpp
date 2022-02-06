/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2020 19:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 106400 KB                            
*  problem: https://codeforces.com/contest/369/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3+4;
int aa[N+2],hn[N+2][N+2],zr[N+2][N+2],n,k,d[N+2][N+2];
queue<pair<int,int> >q;
void upd(int i,int j,int a,int b)
{
  if(d[i][j]+1<d[a][b])
  {
    d[a][b]=d[i][j]+1;
    q.push({a,b});
  }
}
void bfs()
{
  for(int i=1;i<=n+2;i++)
  {
    for(int j=1;j<=n+2;j++)
      d[i][j]=1e9;
  }
  q.push({1,2});d[1][2]=0;
   while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int i=p.first,j=p.second;
     if(j>n)continue;
     if(hn[i][i])
    {
      if(hn[j][n])upd(i,j,j+1,j+2);
      else if(zr[j][n])upd(i,j,i,j+1);
      else 
      {
        upd(i,j,i,j+1);upd(i,j,j+1,j+2);
      }
    }
    else if(zr[i][i])
    {
      if(hn[j][n])upd(i,j,j,j+1);
      else if(zr[j][n]);
      else
      {
        upd(i,j,j,j+1);
      }
    }
    else
    {
      if(hn[j][n])
      {
        upd(i,j,j,j+1);upd(i,j,j+1,j+2);
      }
      else if(zr[j][n])
      {
        upd(i,j,i,j+1);
      }
      else 
      {
        upd(i,j,j,j+1);upd(i,j,i,j+1);
        upd(i,j,j+1,j+2);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==100)hn[i][i]=1;
    if(aa[i]==0)zr[i][i]=1;
    for(int j=i+1;j<=n;j++)
    {
      hn[i][j]=hn[i][j-1]|(aa[j]==100);
      zr[i][j]=zr[i][j-1]&(aa[j]==0);
    }
  }
  bfs();int cnt=0;
  for(int i=1;i<=n+2;i++)
  {
    for(int j=1;j<=n+2;j++)
    {
      //if(v[i][j])cout<<i<<" "<<j<<endl;
      if(d[i][j]<=k)cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}