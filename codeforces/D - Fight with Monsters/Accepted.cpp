/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1296/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,a,b,k;cin>>n>>a>>b>>k;
  vector<int>v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
     int tr=(x-1)/(a+b);
    x-=tr*(a+b);
     //cout<<(x-1)/a<<endl;
    v.push_back((x-1)/a);
  }
  sort(v.begin(),v.end());
   int ans=0;
  for(auto x:v)
  {
    k-=x;if(k>=0)ans++;
    else break;
  }
  cout<<ans<<endl;
  return 0;
}