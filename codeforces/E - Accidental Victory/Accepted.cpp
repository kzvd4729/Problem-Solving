/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 21:09                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 24600 KB                             
*  problem: https://codeforces.com/contest/1490/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
pair<long,long>p[N+2];
long sm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>p[i].first;
      p[i].second=i;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)sm[i]=sm[i-1]+p[i].first;
    vector<int>v;
     v.push_back(p[n].second);
    for(int i=n-1;i>=1;i--)
    {
      if(sm[i]<p[i+1].first)break;
      v.push_back(p[i].second);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto x:v)cout<<x<<" ";cout<<endl;
  }
  return 0;
}