/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2018 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1065/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long s,a,b,c,ans=0;cin>>s>>a>>b>>c;
    long ch=s/c;
    ans+=ch;
    ans+=(ch/a)*b;
    cout<<ans<<endl;
  }
  return 0;
}