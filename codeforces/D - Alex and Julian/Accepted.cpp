/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2019 16:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1220/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<long>v[64];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    long x,r;cin>>x;int cnt=0;r=x;
    while(x){if(x&1)break;x/=2;cnt++;}
    v[cnt].push_back(r);
  }
  int mx=0,id;
  for(int i=0;i<64;i++)
    if(v[i].size()>mx)mx=v[i].size(),id=i;
  cout<<n-mx<<endl;
  for(int i=0;i<64;i++)
  {
    if(i==id)continue;
    for(auto x:v[i])
      cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}