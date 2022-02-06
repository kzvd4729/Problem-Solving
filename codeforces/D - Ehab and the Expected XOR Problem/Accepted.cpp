/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/16/2019 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1174/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<int>v;v.push_back(1);
  for(int i=1;i<=18;i++)
  {
    vector<int>tmp=v;
    v.push_back(1<<i);
    for(auto x:tmp)v.push_back(x);
  }
  int n,x;cin>>n>>x;
  if(x>=(1<<n))
  {
    cout<<(1<<n)-1<<endl;
    for(int i=0;i<(1<<n)-1;i++)
      cout<<v[i]<<" ";
    cout<<endl;exit(0);
  }
  int un=(1<<(n-1));
  for(auto &z:v)
    if(__builtin_clz(x)==__builtin_clz(z))z=un;
  cout<<(1<<(n-1))-1<<endl;
  for(int i=0;i<(1<<(n-1))-1;i++)
    cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}