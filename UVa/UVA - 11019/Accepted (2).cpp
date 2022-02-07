/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-03 12:08:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 1720                                            memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11019
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int t,n,m,x,y,qmt[N+2][N+2],qmp[N+2][N+2];
int tx[N+2][N+2],pt[N+2][N+2];
string s;
int sum_tx(int ii,int jj,int i,int j)
{
  int sum=qmt[i][j];
  sum-=qmt[i][jj-1];
  sum-=qmt[ii-1][j];
  sum+=qmt[ii-1][jj-1];
  return sum;
}
int sum_pt(int ii,int jj,int i,int j)
{
  int sum=qmp[i][j];
  sum-=qmp[i][jj-1];
  sum-=qmp[ii-1][j];
  sum+=qmp[ii-1][jj-1];
  return sum;
}
bool ok(int ii,int jj,int i,int j)
{
  if(sum_tx(ii,jj,i,j)!=sum_pt(1,1,x,y))return false;
  for(int k=1;k<=50;k++)
  {
    int r=1+rand()%x;
    int c=1+rand()%y;
    if(sum_pt(1,1,r,c)!=sum_tx(ii,jj,ii+r-1,jj+c-1))return false;
    if(sum_pt(r,c,x,y)!=sum_tx(ii+r-1,jj+c-1,i,j))return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
      {
        tx[i][j]=s[j-1]-'a';
      }
    }
    cin>>x>>y;
    for(int i=1;i<=x;i++)
    {
      cin>>s;
      for(int j=1;j<=y;j++)
      {
        pt[i][j]=s[j-1]-'a';
      }
    }
    memset(qmt,0,sizeof(qmt));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        qmt[i][j]=tx[i][j]+qmt[i][j-1];
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        qmt[i][j]+=qmt[i-1][j];
      }
    }
    memset(qmp,0,sizeof(qmp));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        qmp[i][j]=pt[i][j]+qmp[i][j-1];
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        qmp[i][j]+=qmp[i-1][j];
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int ii=i-x+1;
        int jj=j-y+1;
        if(ii<1||jj<1)continue;
        if(ok(ii,jj,i,j))ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}