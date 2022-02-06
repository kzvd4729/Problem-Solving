/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 20:40                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/988/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,x;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    mp[x]=i;
  }
  if(mp.size()<k)cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    for(auto x:mp)
    {
      if(k==0)break;
      cout<<x.second<<" ";
      k--;
    }
    cout<<endl;
  }
  return 0;
}