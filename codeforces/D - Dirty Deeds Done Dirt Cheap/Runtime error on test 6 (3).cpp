/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/13/2019 20:37                        
*  solution_verdict: Runtime error on test 6                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1148/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct _data
{
  int x,y,id;
};
bool cmp1(_data A,_data B)
{
  return A.y>B.x;
}
bool cmp2(_data A,_data B)
{
  return A.y<B.x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<_data>aa,bb;int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    if(x<y)aa.push_back({x,y,i});
    else bb.push_back({x,y,i});
  }
  sort(aa.begin(),aa.end(),cmp1);
  sort(bb.begin(),bb.end(),cmp2);
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