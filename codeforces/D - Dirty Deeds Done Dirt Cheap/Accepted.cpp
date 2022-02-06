/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/13/2019 22:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 9300 KB                              
*  problem: https://codeforces.com/contest/1148/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct da
{
  int x,y,id;
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<da>aa,bb;int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    if(x<y)aa.push_back({x,y,i});
    else bb.push_back({x,y,i});
  }
  sort(aa.begin(),aa.end(),[](da A,da B){return A.y>B.y;});
  sort(bb.begin(),bb.end(),[](da A,da B){return A.y<B.y;});
  if(aa.size()>=bb.size())
  {
    cout<<aa.size()<<endl;
    for(auto z:aa)
      cout<<z.id<<" ";
    cout<<endl;
  }
  else
  {
    cout<<bb.size()<<endl;
    for(auto z:bb)
      cout<<z.id<<" ";
    cout<<endl;
  }
  return 0;
}