/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2018 21:52                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++11                               
*  run_time: 77 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/985/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,k,l,arr[N+2],nn,ans,lid,vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>l;
  nn=n*k;
  for(int i=1;i<=nn;i++)
    cin>>arr[i];
  sort(arr+1,arr+nn+1);
   vector<int>v;
  v.push_back(arr[1]);
  for(int i=2;i<=nn;i++)
  {
    if(arr[i]-arr[1]<=l)
      v.push_back(arr[i]);
  }
  if(v.size()<n)cout<<0<<endl,exit(0);
   vector<int>st;
  st.push_back(v[0]);
  vis[0]=1;
   lid=0;
   for(int i=1;i<v.size();i++)
  {
    if(i-lid>=k)
    {
      st.push_back(v[i]);
      vis[i]=1;
      lid=i;
    }
  }
   if(st.size()>=n)
  {
    for(int i=0;i<n;i++)
      ans+=st[i];
    cout<<ans<<endl,exit(0);
  }
  n-=st.size();
  for(int i=v.size()-1;i>=0;i--)
  {
    if(vis[i])continue;
    if(n)
    {
      vis[i]=1;
      n--;
    }
  }
  for(int i=0;i<v.size();i++)
    if(vis[i])ans+=v[i];
  cout<<ans<<endl;
  return 0;
}