/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1316/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;string s,a,b;cin>>n>>s;
    string c;int id=1e9;
    for(int i=1;i<=n+n;i++)c.push_back('z');
    for(int k=1;k<=n;k++)
    {
      a=s.substr(n-k,k);
      b=s.substr(0,n-k);
      if(k%2)reverse(b.begin(),b.end());
      if(a+b<=c)c=a+b,id=min(id,n-k);
    }
    cout<<c<<"\n"<<id+1<<"\n";
  }
  return 0;
}