/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2019 12:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/gym/102428/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
long qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int sl;cin>>sl;int n=s.size();
  long ans=1LL*n*sl;
  for(int i=0;i<n;i++)s.push_back(s[i]);
  vector<int>v;
 for(int i=0;i<n+n;i++)
  if(s[i]=='E')v.push_back(i);
 v.push_back(1e9);
 //cout<<ans<<endl;
  for(int i=0;i<n;i++)
 {
  int nx=lower_bound(v.begin(),v.end(),i)-v.begin();
  ans-=min(sl,(v[nx]-i));
 }
 cout<<ans<<endl;
   return 0;
}