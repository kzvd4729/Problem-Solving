/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 23:46                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 19500 KB                             
*  problem: https://codeforces.com/contest/1004/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int t,fr[N+2],frr[N+2],mx,eq,x;
void check(int n,int m)
{
  int mat[n+2][m+2];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      mat[i][j]=-1;
  int xx=mx+2-m+eq-1;
  int yy=m-eq+1;
  memset(frr,0,sizeof(frr));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=abs(i-xx)+abs(j-yy);
      frr[mat[i][j]]++;
    }
  }
  for(int i=0;i<=mx;i++)
    if(fr[i]!=frr[i])return ;
  cout<<n<<" "<<m<<endl;
  cout<<xx<<" "<<yy<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>t;
  for(int i=1;i<=t;i++)
  {
    cin>>x;
    mx=max(mx,x);
    fr[x]++;
  }
  if(fr[0]!=1)cout<<-1<<endl,exit(0);
  int now=0;
  for(int i=1; ;i++)
  {
    now+=4;
    if(fr[i]!=now)
    {
      eq=i;
      break;
    }
  }
  for(int i=1;i<=t;i++)
  {
    if(t%i==0)
      check(i,t/i);
  }
  cout<<-1<<endl;
  return 0;
}