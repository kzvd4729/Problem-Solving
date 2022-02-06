/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2019 19:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1228/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ck(int x)
{
  vector<int>v;
  while(x)
  {
    v.push_back(x%10);
    x/=10;
  }
  sort(v.begin(),v.end());
  for(int i=1;i<v.size();i++)
    if(v[i]==v[i-1])return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int l,r;cin>>l>>r;
  for(int i=l;i<=r;i++)
  {
    if(ck(i))cout<<i<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}