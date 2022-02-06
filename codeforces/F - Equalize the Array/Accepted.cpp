/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 21:01                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 171 ms                                          memory_used: 22300 KB                             
*  problem: https://codeforces.com/contest/1490/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
 int compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
  return (int)v.size();
}
int fr[N+2],sm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     int mx=compress(n);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    for(int i=1;i<=mx;i++)fr[i]=0;
    for(int i=1;i<=n;i++)fr[a[i]]++;
     vector<int>v;
    for(int i=1;i<=mx;i++)v.push_back(fr[i]);
    sort(v.begin(),v.end());
     sm[mx]=0;
    for(int i=mx-1;i>=0;i--)sm[i]=sm[i+1]+v[i];
     int ans=inf,now=0;
    //for(auto x:v)cout<<x<<" ";cout<<endl;
    for(int i=0;i<mx;i++)
    {
      ans=min(ans,now+sm[i]-(mx-i)*v[i]);
      now+=v[i];
    }
    cout<<ans<<endl;
  }
  return 0;
}