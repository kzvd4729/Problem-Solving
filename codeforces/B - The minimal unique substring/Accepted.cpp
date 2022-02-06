/****************************************************************************************
*  @author: kzvd4729                                         created: May/12/2019 22:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1158/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  if(n==k)
  {
    while(n--)cout<<'0';
    exit(0);
  }
  int zero=(n-k)/2;
  string s;
  while(true)
  {
    if(s.size()==n)break;
    for(int i=1;i<=zero;i++)
    {
      s.push_back('0');
      if(s.size()==n)break;
    }
    if(s.size()==n)break;
    s.push_back('1');
  }
  cout<<s<<endl;
  return 0;
}