/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 11:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1332/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
int aa[N+2];
int compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(aa[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
  return v.size();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<int>pr;
  for(int i=2;i<=33;i++)
  {
    if(isPrime(i))pr.push_back(i);
  }
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      for(int j=1;j<=pr.size();j++)
        if(x%pr[j-1]==0)aa[i]=j;
    }
    cout<<compress(n)<<"\n";
    for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<"\n";
  }
  return 0;
}