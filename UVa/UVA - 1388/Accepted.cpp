/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-24 01:59:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 120                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1388
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m;
double dp[N+2][N+N+2],aa[N+2],bb[N+N+2];
bitset<2003>vs[N+2];
double dis(double a,double b)
{
  double ang=abs(a-b);
  return 10000.0*(ang/360.0);
}
double dfs(int i,int j)
{
  if(i>n)return 0;if(j>m+n)return 1e9;
  if(vs[i][j])return dp[i][j];vs[i][j]=1;
  double ans=dfs(i,j+1);
  ans=min(ans,dis(aa[i],bb[j])+dfs(i+1,j+1));
  return dp[i][j]=ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>m)
  {
    double un=360.0/(n*1.0);
    aa[0]=0;
    for(int i=1;i<=n;i++)
      aa[i]=aa[i-1]+un;

    un=360.0/((n+m)*1.0);
    bb[0]=0;
    for(int i=1;i<=n+m;i++)
      bb[i]=bb[i-1]+un;
    for(int i=1;i<=n;i++)vs[i].reset();
    cout<<setprecision(4)<<fixed<<dfs(1,1)<<endl;
  }
  return 0;
}