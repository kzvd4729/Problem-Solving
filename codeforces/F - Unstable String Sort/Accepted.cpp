/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/30/2019 21:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1213/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bb[N+2],paa[N+2],pbb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i],paa[aa[i]]=i;
  for(int i=1;i<=n;i++)cin>>bb[i],pbb[bb[i]]=i;
  int cnt=0,i=0,j=0;vector<int>v;
  while(i<n)
  {
    cnt++;int nwa=i+1,nwb=j,pra=-1,prb=-1;
    while(true)
    {
      while(i<nwa)
        nwb=max(nwb,pbb[aa[++i]]);
      while(j<nwb)
        nwa=max(nwa,paa[bb[++j]]);
      if(nwa==pra&&nwb==prb)break;
      pra=nwa,prb=nwb;
    }
    v.push_back(i);
  }
  if(cnt<k)cout<<"NO\n",exit(0);
  cout<<"YES\n";
  while(v.size()>26)v.pop_back();
  string s;
  for(int i=1;i<=n;i++)s.push_back('z');
  int ls=0;char c='a';
  for(auto x:v)
  {
    for(int i=ls+1;i<=x;i++)
      s[aa[i]-1]=c;
    c++;ls=x;
  }
  cout<<s<<endl;
  return 0;
}