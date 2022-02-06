/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 20:45                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 499 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/982/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,x;
string s;
set<pair<int,int> >intro,emty;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    emty.insert({x,i});
  }
  cin>>s;
  for(auto x:s)
  {
    pair<int,int>p;
    if(x=='0')
    {
      p=*emty.begin();
      emty.erase(p);
      cout<<p.second<<" ";
      intro.insert(p);
    }
    else
    {
      p=*intro.rbegin();
      intro.erase(p);
      cout<<p.second<<" ";
    }
  }
  cout<<endl;
  return 0;
}