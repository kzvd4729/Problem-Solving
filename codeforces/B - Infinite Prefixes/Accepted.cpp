/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2020 21:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1295/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,b;cin>>n>>b;string s;cin>>s;
    int bl=0;vector<int>v;//v.push_back(0);
    for(auto x:s)
    {
      if(x=='0')bl++;else bl--;
      v.push_back(bl);
    }
    if(bl==0)
    {
      int f=0;
      for(auto x:v)if(x==b)f=1;
      if(f)cout<<-1<<'\n';else cout<<0<<'\n';
      continue;
    }
    int ans=0;
    for(auto x:v)
    {
      int df=b-x;
      if(df<0&&bl>0)continue;
      if(df>0&&bl<0)continue;
       if(abs(df)%abs(bl)==0)ans++;
    }
    if(b==0)ans++;
    cout<<ans<<'\n';
  }
  return 0;
}