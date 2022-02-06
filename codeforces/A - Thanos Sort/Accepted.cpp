/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/01/2019 21:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1145/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
bool isok(int i,int j)
{
  int f=0;
  for(int k=i+1;k<=j;k++)
    if(aa[k]<aa[k-1])f=1;
  return !f;
}
int dfs(int i,int j)
{
  if(isok(i,j))return j-i+1;
  int md=(i+j)/2;
  return max(dfs(i,md),dfs(md+1,j));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  cout<<dfs(1,n)<<endl;
  return 0;
}