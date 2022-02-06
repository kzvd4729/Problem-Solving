/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 11:58                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/525/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int rw[N+2][N+2],cl[N+2][N+2],vs[N+2][N+2];
string s[N+2];
void visitR(int i,int b,int d)
{
  for(int j=b;j<=d;j++)vs[i][j]=1;
}
void visitC(int j,int a,int c)
{
  for(int i=a;i<=c;i++)vs[i][j]=1;
}
void dfs(int a,int b,int c,int d,int f)
{
  if(c-a+1<=0||d-b+1<=0)return ;
  //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f<<endl;
  if(f)
  {
    int rq=d-b+1,pr=a-1;
    for(int i=a;i<=c;i++)
    {
      if(rw[i][b]<rq)continue;
      dfs(pr+1,b,i-1,d,f^1);pr=i;
      visitR(i,b,d);
    }
    dfs(pr+1,b,c,d,f^1);
  }
  else
  {
    int ok=0;
    int rq=c-a+1,pr=b-1;
    for(int j=b;j<=d;j++)
    {
      if(cl[a][j]<rq)continue;
      dfs(a,pr+1,c,j-1,f^1);pr=j,ok=1;
      visitC(j,a,c);
    }
    if(!ok)return ;
    dfs(a,pr+1,c,d,f^1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="#"+s[i];
   for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=m;j>=1;j--)
    {
      if(s[i][j]=='*')cnt++;
      else cnt=0;rw[i][j]=cnt;
    }
  }
  for(int j=1;j<=m;j++)
  {
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
      if(s[i][j]=='*')cnt++;
      else cnt=0;cl[i][j]=cnt;
    }
  }
  dfs(1,1,n,m,1);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(!vs[i][j])s[i][j]='.';
      cout<<s[i][j];
    }
    cout<<"\n";
  }
  return 0;
}