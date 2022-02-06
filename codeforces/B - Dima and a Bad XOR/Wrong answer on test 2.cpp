/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 15:33                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1000 KB                              
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
  int a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    a^=aa[i][1];u.push_back(aa[i][1]);
    int f=0;
    for(int j=2;j<=m;j++)
    {
      if((b^aa[i][j])!=a)
      {
        f=1;
        b^=aa[i][j];v.push_back(aa[i][j]);
        break;
      }
    }
    if(!f)
    {
      b^=aa[i][m];
      v.push_back(aa[i][m]);
    }
  }
  if(!a&&!b)cout<<"NIE"<<endl,exit(0);
  cout<<"TAK"<<endl;
  if(a)for(auto x:u)cout<<x<<" ";
  else for(auto x:v)cout<<x<<" ";
  cout<<endl;
  return 0;
}