/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 11 ms                                           memory_used: 1600 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int l,r,d;cin>>l>>r>>d;vector<int>ans;
  for(int i=l;i<=r;i++)
  {
    if(i%d==0)ans.push_back(i);
  }
  int gc=0;
  for(auto x:ans)
    gc=__gcd(gc,x);
  if(gc!=d)cout<<"impossible"<<endl,exit(0);
  if(ans.size()==0)cout<<"impossible"<<endl,exit(0);
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}