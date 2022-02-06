/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/1340/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3,inf=1e9;
string d[]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
string a[N+2];int n;
int mm[N+2][N+2];
int ds(int i,int j)
{
  if(mm[i][j]!=-1)return mm[i][j];
  string &sub=a[i],&sup=d[j];
  int cnt=0;
  for(int k=0;k<7;k++)
  {
    if(sub[k]!=sup[k])
    {
      if(sub[k]=='1')return mm[i][j]=inf;
      cnt++;
    }
  }
  return mm[i][j]=cnt;
}
int ans[N+2],vis[N+2][N+2];
void dfs(int i,int rm)
{
  if(i>n)
  {
    if(rm)return ;
    for(int j=1;j<=n;j++)
      cout<<ans[j];
    cout<<endl;exit(0);
  }
  if(vis[i][rm])return ;
  for(int j=9;j>=0;j--)
  {
    int mn=ds(i,j);
    if(mn<=rm)
    {
      ans[i]=j;dfs(i+1,rm-mn);
    }
  }
  vis[i][rm]=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  memset(mm,-1,sizeof(mm));
  dfs(1,k);cout<<-1<<endl;
  return 0;
}