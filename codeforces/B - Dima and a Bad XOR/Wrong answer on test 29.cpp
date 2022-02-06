/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 15:40                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1151/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int aa[N+2][N+2];
vector<int>u,v;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>aa[i][j];
  int rw=-1;
  for(int i=1;i<=n;i++)
  {
    for(int j=2;j<=m;j++)
    {
      if(aa[i][j]!=aa[i][j-1])
        rw=i;
    }
  }
  if(rw==-1)
  {
    int xxr=0;
    for(int i=1;i<=n;i++)
      xxr^=aa[i][1];
    if(!xxr)cout<<"NIE"<<endl,exit(0);
    cout<<"TAK"<<endl;
    for(int i=1;i<=n;i++)
      cout<<1<<" ";
    cout<<endl;exit(0);
  }
  cout<<"TAK"<<endl;
  int xxr=0;
  for(int i=1;i<=n;i++)
  {
    if(i==rw)continue;
    xxr^=aa[i][1];
  }
  for(int j=1;j<=m;j++)
  {
    if((xxr^aa[rw][j]))
    {
      for(int i=1;i<=n;i++)
      {
        if(i==rw)cout<<j<<" ";
        else cout<<i<<" ";
      }
      cout<<endl;exit(0);
    }
  }
  return 0;
}