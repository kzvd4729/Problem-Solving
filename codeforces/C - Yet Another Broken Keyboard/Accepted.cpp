/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/12/2019 19:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1272/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   string s;cin>>s;
   for(int i=1;i<=k;i++)
  {
    char c;cin>>c;vis[c-'a']=1;
  }
  long ans=0;
  int cnt=0;s.push_back('#');
  for(auto x:s)
  {
    int c=x-'a';
    if(vis[c])cnt++;
    else {ans+=((1LL*cnt*(cnt+1)))/2;cnt=0;}
  }
  cout<<ans<<endl;
  return 0;
}