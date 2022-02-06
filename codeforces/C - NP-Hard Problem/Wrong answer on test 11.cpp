/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 12:41                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/688/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void inv(void)
{
  cout<<"-1"<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;set<int>x,y;
  while(m--)
  {
    int u,v;cin>>u>>v;
    if(x.find(u)!=x.end()&&x.find(v)!=x.end())inv();
    if(y.find(u)!=y.end()&&y.find(v)!=y.end())inv();
    if(y.find(u)==y.end()&&x.find(v)==x.end())
      x.insert(u),y.insert(v);
    else if(y.find(v)==y.end()&&x.find(u)==x.end())
      x.insert(v),y.insert(u);
  }
  cout<<x.size()<<endl;
  for(auto z:x)
    cout<<z<<" ";
  cout<<endl;
  cout<<y.size()<<endl;
  for(auto z:y)
    cout<<z<<" ";
  cout<<endl;
  return 0;
}