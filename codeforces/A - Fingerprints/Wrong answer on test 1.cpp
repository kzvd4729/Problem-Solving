/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2018 11:25                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/994/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,x,arr[102],vis[102];
int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>arr[i];
for(int i=1;i<=m;i++)
cin>>x,vis[x]=1;
for(int i=1;i<=n;i++)
if(vis[i])cout<<i<<" ";
cout<<endl;
 return 0;
}