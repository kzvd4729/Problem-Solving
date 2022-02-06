/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2019 16:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/471/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
vector<int>zfunction(vector<int>s)
{
  int n=s.size();vector<int>z(n);
  z[0]=0;//l,r maintains a window with maximum r
  for(int i=1,l=0,r=0;i<n;i++)
  {
    if(i<=r)z[i]=min(r-i+1,z[i-l]);//inside the window
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;//brute-force
    if(i+z[i]-1>r)l=i,r=i+z[i]-1;//r update
  }
  return z;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;vector<int>aa,bb;
  if(b>a)cout<<0<<endl,exit(0);
  if(b==1)cout<<a<<endl,exit(0);
   int pr;cin>>pr;
  for(int i=2;i<=a;i++)
  {
    int x;cin>>x;aa.push_back(x-pr);
    pr=x;
  }
  cin>>pr;
  for(int i=2;i<=b;i++)
  {
    int x;cin>>x;bb.push_back(x-pr);
    pr=x;
  }
  bb.push_back(2e9+1);
  for(auto x:aa)bb.push_back(x);
  vector<int>z=zfunction(bb);
  int ans=0;
  for(auto x:z)ans+=(x==b-1);
  cout<<ans<<endl;
  return 0;
}