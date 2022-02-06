/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2018 21:53                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 109 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/985/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,k,l,arr[N+2],nn,ans,lid,vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>l;
  nn=n*k;
  for(long i=1;i<=nn;i++)
    cin>>arr[i];
  sort(arr+1,arr+nn+1);
   vector<long>v;
  v.push_back(arr[1]);
  for(long i=2;i<=nn;i++)
  {
    if(arr[i]-arr[1]<=l)
      v.push_back(arr[i]);
  }
  if(v.size()<n)cout<<0<<endl,exit(0);
   vector<long>st;
  st.push_back(v[0]);
  vis[0]=1;
   lid=0;
   for(long i=1;i<v.size();i++)
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
    for(long i=0;i<n;i++)
      ans+=st[i];
    cout<<ans<<endl,exit(0);
  }
  n-=st.size();
  for(long i=v.size()-1;i>=0;i--)
  {
    if(vis[i])continue;
    if(n)
    {
      vis[i]=1;
      n--;
    }
  }
  for(long i=0;i<v.size();i++)
    if(vis[i])ans+=v[i];
  cout<<ans<<endl;
  return 0;
}