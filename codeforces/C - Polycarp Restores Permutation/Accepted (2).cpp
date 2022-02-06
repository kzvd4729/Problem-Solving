/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 14:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 13200 KB                             
*  problem: https://codeforces.com/contest/1141/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long aa[N+2],bb[N+2];
map<long,long>mp;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 long n;cin>>n;aa[1]=N;
 for(long i=2;i<=n;i++)
 {
  long x;cin>>x;bb[i]=x;
  aa[i]=aa[i-1]+x;
 }
 vector<long>v;
 for(long i=1;i<=n;i++)
  v.push_back(aa[i]);
 sort(v.begin(),v.end());
 long cnt=0;
 for(long i=0;i<n;i++)
 {
  if(mp[v[i]])cout<<-1<<endl,exit(0);
  mp[v[i]]=++cnt;
 }
 for(long i=1;i<=n;i++)
  aa[i]=mp[aa[i]];
 for(long i=2;i<=n;i++)
 {
  if(aa[i]-aa[i-1]!=bb[i])
   cout<<-1<<endl,exit(0);
 }
 for(long i=1;i<=n;i++)
  cout<<aa[i]<<" ";
 cout<<endl;
 return 0;
}