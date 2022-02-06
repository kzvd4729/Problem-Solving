/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 15:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1011/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int n,m,x,fr[N+2],id,arr[N+2];
bool possible(int x)
{
  int cnt=0;
  for(int i=1;i<=id;i++)
    cnt+=arr[i]/x;
  return cnt>=n;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x;
    fr[x]++;
  }
  for(int i=1;i<=N;i++)
    if(fr[i])arr[++id]=fr[i];
  sort(arr+1,arr+id+1);
   for(int i=N;i>=1;i--)
    if(possible(i))cout<<i<<endl,exit(0);
  cout<<0<<endl;
  return 0;
}