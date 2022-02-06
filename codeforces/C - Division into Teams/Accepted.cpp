/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2018 10:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/149/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x;
vector<pair<int,int> >v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    v.push_back({x,i});
  }
  sort(v.begin(),v.end());
  int s1=0,s2=0;
  vector<int>v1,v2;
  for(auto x:v)
  {
    if(s1<=s2)v1.push_back(x.second),s1+=x.first;
    else v2.push_back(x.second),s2+=x.first;
  }
  cout<<v1.size()<<endl;
  for(auto x:v1)cout<<x<<" ";
  cout<<endl;
  cout<<v2.size()<<endl;
  for(auto x:v2)cout<<x<<" ";
  cout<<endl;
  return 0;
}
 