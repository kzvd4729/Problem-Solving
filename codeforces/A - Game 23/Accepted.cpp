/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1141/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long n,m;
map<long,long>mp;
void dfs(long n,long cnt)
{
 if(n==m)
 {
  cout<<cnt<<endl,exit(0);
 }
 if(n>m)return ;
 if(mp[n])return ;
 dfs(n*2,cnt+1);dfs(n*3,cnt+1);
 mp[n]=1;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n>>m;dfs(n,0);
 cout<<-1<<endl;
 return 0;
}