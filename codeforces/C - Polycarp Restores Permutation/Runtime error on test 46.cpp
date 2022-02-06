/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 20:53                        
*  solution_verdict: Runtime error on test 46                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1141/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],mp[N+N+2],bb[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;aa[1]=N;
 for(int i=2;i<=n;i++)
 {
  int x;cin>>x;bb[i]=x;
  aa[i]=aa[i-1]+x;
 }
 vector<int>v;
 for(int i=1;i<=n;i++)
  v.push_back(aa[i]);
 sort(v.begin(),v.end());
 int cnt=0;
 for(int i=0;i<n;i++)
 {
  if(mp[v[i]])cout<<-1<<endl,exit(0);
  mp[v[i]]=++cnt;
 }
 for(int i=1;i<=n;i++)
  aa[i]=mp[aa[i]];
 for(int i=2;i<=n;i++)
 {
  if(aa[i]-aa[i-1]!=bb[i])
   cout<<-1<<endl,exit(0);
 }
 for(int i=1;i<=n;i++)
  cout<<aa[i]<<" ";
 cout<<endl;
 return 0;
}