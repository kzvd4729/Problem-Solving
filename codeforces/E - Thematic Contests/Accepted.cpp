/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 8500 KB                              
*  problem: https://codeforces.com/contest/1077/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>fr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  vector<int>v;
  for(auto x:fr)
    v.push_back(x.second);
  sort(v.begin(),v.end());
  int mx=0;
  for(int i=v.size()-1;i>=0;i--)
  {
    int pr=1e9;
    for(int j=i;j>=0;j--)
    {
      int rq=min(pr/2,v[j]);
      if(!rq)break;
      int el=i-j+1;
      int sum=rq*((1<<el)-1);
      mx=max(mx,sum);pr=rq;
    }
  }
  cout<<mx<<endl;
  return 0;
}