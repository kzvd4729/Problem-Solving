/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2019 14:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 5900 KB                              
*  problem: https://codeforces.com/gym/102428/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int tmp[N+2][N+2],n,m;
string s[N+2];
bool isOk(int d)
{
  memset(tmp,0,sizeof(tmp));
  for(int i=0;i<n;i++)
  {
    int cnt=1;
    for(int j=m-2;j>=0;j--)
    {
      if(s[i][j]==s[i][j+1])cnt++;
      else cnt=1;
       if(cnt>=d)tmp[i][j]=1;
    }
  }
  for(int j=0;j<m;j++)
  {
    for(int i=n-2;i>=0;i--)
    {
      if(tmp[i][j])tmp[i][j]+=tmp[i+1][j];
      if(tmp[i][j]>=d)return true;
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
  if(min(m,n)==1)cout<<1<<endl,exit(0);
   int lo=2,hi=min(m,n),md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(isOk(md))lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(isOk(md))break;
  cout<<md*md<<endl;
    return 0;
}