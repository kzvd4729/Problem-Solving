/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 14:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/632/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    if(s=="half")aa[i]=0;
    else aa[i]=1;
  }
  long app,ans=0;
  for(int i=n;i>=1;i--)
  {
    if(i==n)app=1;
    else app=app*2+aa[i];
    ans+=((app/2)*1LL)*p;
    if(app%2)ans+=(p/2);
  }
  cout<<ans<<endl;
  return 0;
}