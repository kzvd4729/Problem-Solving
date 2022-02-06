/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1294/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int b,c;
bool ok(int x,int a)
{
  int sq=sqrt(x+1);
  for(int i=2;i<=sq;i++)
  {
    if(x%i)continue;
    b=i,c=x/i;
    if(a!=b&&b!=c&&a!=c&&c>1)return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int sq=sqrt(n+1);
    int f=0;
    for(int i=2;i<=sq;i++)
    {
      if(n%i)continue;
      if(ok(i,i))
      {
        cout<<"YES\n";
        f=1;cout<<n/i<<" "<<b<<" "<<c<<"\n";
        break;
      }
      if(ok(n/i,i))
      {
        cout<<"YES\n";
        f=1;cout<<i<<" "<<b<<" "<<c<<"\n";
        break;
      }
    }
    if(!f)cout<<"NO\n";
  }
  return 0;
}