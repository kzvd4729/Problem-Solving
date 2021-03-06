/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2019 23:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/1136/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int n,m,a[N+2][N+2],b[N+2][N+2];
void no(void)
{
  cout<<"NO"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>b[i][j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    vector<int>u,v;
    for(int j=1;j<=m;j++)
    {
      if(i-(j-1)==0)break;
      u.push_back(a[i-(j-1)][j]);
      v.push_back(b[i-(j-1)][j]);
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    if(u!=v)no();
  }
  for(int i=2;i<=m;i++)
  {
    vector<int>u,v;int mn=0;
    for(int j=i;j<=m;j++)
    {
      if(n-mn==0)break;
      u.push_back(a[n-mn][j]);
      v.push_back(b[n-mn][j]);
      mn++;
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    if(u!=v)no();
  }
  cout<<"YES"<<endl;
  return 0;
}