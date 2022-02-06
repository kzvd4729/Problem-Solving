/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1157/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cnt;map<int,int>mp;
void dfs(int n)
{
  if(mp[n])return ;
  mp[n]=1;cnt++;
  n++;
  while(n%10==0)n/=10;
  dfs(n);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  dfs(n);cout<<cnt<<endl;
   return 0;
}