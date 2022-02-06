/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/19/2021 20:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1474/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9,mod=1e9+7;
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<int>v;
  for(int i=2;i<=30000;i++)if(isPrime(i))v.push_back(i);
   int t;cin>>t;
  while(t--)
  {
    int d;cin>>d;
    int a=lower_bound(v.begin(),v.end(),1+d)-v.begin();
    int b=lower_bound(v.begin(),v.end(),v[a]+d)-v.begin();
    cout<<v[a]*v[b]<<" ";
  }
   return 0;
}