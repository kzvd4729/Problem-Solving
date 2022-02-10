/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-20 19:56:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 29                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1419
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1000000007;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int sm=0;
    for(int i=1;i<=n;i++)
      sm=(sm+big(k,__gcd(n,i)))%mod;
    //cout<<sm<<endl;
    cout<<"Case "<<++tc<<": "<<(1LL*sm*big(n,mod-2))%mod<<"\n";
  }
  return 0;
}