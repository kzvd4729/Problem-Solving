/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 13:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 22600 KB                             
*  problem: https://codeforces.com/contest/765/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],con[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)cin>>aa[i],st.insert(aa[i]);
   int m=st.size(),id=0;
  for(auto x:st)cc[++id]=x,con[x]=id;
  for(int i=1;i<=n;i++)bb[i]=con[aa[i]];
   for(int i=1;i<=m;i++)
    if(bb[cc[i]]!=i)cout<<-1<<endl,exit(0);
  cout<<m<<endl;
  for(int i=1;i<=n;i++)cout<<bb[i]<<" ";cout<<endl;
  for(int i=1;i<=m;i++)cout<<cc[i]<<" ";cout<<endl;
   return 0;
}