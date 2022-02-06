/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/13/2020 20:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1301/problem/A
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
    string a,b,c;cin>>a>>b>>c;
    for(int i=0;i<a.size();i++)
    {
      if(c[i]==b[i])a[i]=c[i];
      else b[i]=c[i];
    }
    if(a==b)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}