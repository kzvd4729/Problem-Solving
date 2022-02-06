/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 22:14                        
*  solution_verdict: Wrong answer on pretest 14              language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1305/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
  }
  set<int>st;
  for(int i=1;i<=n;i++)
  {
    if(dg[i]==1)st.insert(i);
  }
  while(st.size()>1)
  {
    int a=*st.begin();st.erase(a);
    int b=*st.begin();st.erase(b);
     cout<<"? "<<a<<" "<<b<<endl;
    int c;cin>>c;
    if(c==a||c==b||dg[c]==2)cout<<"! "<<c<<endl,exit(0);
     dg[c]-=2;if(dg[c]==1)st.insert(c);
  }
  if(st.size()==0)assert(0);
  if(st.size()==1)cout<<"! "<<*st.begin()<<endl,exit(0);
  //if(st.size())
  return 0;
}