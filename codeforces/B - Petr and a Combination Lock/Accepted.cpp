/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/05/2019 13:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1097/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[20];
void dfs(int st,int dg)
{
  if(st>n)
  {
    if(!dg)cout<<"YES"<<endl,exit(0);
    return ;
  }
  dfs(st+1,(dg+aa[st])%360);
  dfs(st+1,(dg-aa[st]+360)%360);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  dfs(1,0);
  cout<<"NO"<<endl;
  return 0;
}