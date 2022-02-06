/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2019 23:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1166/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
bitset<10002>ls[52];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,n;cin>>m>>n;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
      cin>>aa[j],ls[i][aa[j]]=1;
    for(int k=1;k<i;k++)
      if((ls[i]&ls[k]).count()==0)
        cout<<"impossible"<<endl,exit(0);
  }
  cout<<"possible"<<endl;
  return 0;
}