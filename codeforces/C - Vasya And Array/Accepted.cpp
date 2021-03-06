/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 21:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1187/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  vector<pair<int,int> >pp[2];
  for(int i=1;i<=m;i++)
  {
    int ty,l,r;cin>>ty>>l>>r;
    pp[ty].push_back({l,r});
  }
  sort(pp[1].begin(),pp[1].end());
  int pt=100000000,mx=0;
  for(auto x:pp[1])
  {
    int l=x.first,r=x.second;
    if(mx<l)
    {
      for(int i=mx+1;i<=l;i++)
        aa[i]=--pt;
    }
    for(int i=l+1;i<=r;i++)
      aa[i]=aa[l];
    mx=max(mx,r);
  }
  for(int i=mx+1;i<=n;i++)
    aa[i]=--pt;
  for(auto x:pp[0])
  {
    int l=x.first,r=x.second;
    int f=0;
    for(int i=l+1;i<=r;i++)
      if(aa[i-1]>aa[i])f=1;
    if(!f)cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}