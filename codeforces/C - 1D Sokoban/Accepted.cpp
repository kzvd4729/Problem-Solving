/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/02/2021 21:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 6800 KB                              
*  problem: https://codeforces.com/contest/1494/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int solve(vector<int>a,vector<int>b)
{
  sort(a.begin(),a.end());sort(b.begin(),b.end());
   vector<int>c=a;
  for(auto x:b)c.push_back(x);
  sort(c.begin(),c.end());
   vector<int>mt;
  for(auto x:a)
  {
    if(binary_search(b.begin(),b.end(),x))mt.push_back(x);
  }
  int mx=0;
  for(int i=(int)c.size()-1;i>=0;i--)
  {
    int now=0;
    int id=lower_bound(mt.begin(),mt.end(),c[i]+1)-mt.begin();
    now+=(int)mt.size()-id;
     id=lower_bound(a.begin(),a.end(),c[i]+1)-a.begin();
     now+=lower_bound(b.begin(),b.end(),c[i]+1)-lower_bound(b.begin(),b.end(),c[i]+1-id);
     mx=max(mx,now);
  }
  return mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    vector<int>a,b,c,d;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(x>0)a.push_back(x);
      else b.push_back(-x);
    }
    for(int i=1;i<=m;i++)
    {
      int x;cin>>x;
      if(x>0)c.push_back(x);
      else d.push_back(-x);
    }
    cout<<solve(a,c)+solve(b,d)<<'\n';
  }  
  return 0;
}