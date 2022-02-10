/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-29 19:56:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1172                                       memory_used (MB): 16.8                            
*  problem: https://vjudge.net/problem/LightOJ-1170
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=1e10;
const long mod=100000007;
const long N=1e5;
long t,tc,a,b,fac[N*10+2];
set<long>st;
vector<long>v;
void precal(void)
{
  fac[0]=1LL;
  for(long i=1;i<=10*N;i++)
    fac[i]=(fac[i-1]*i)%mod;
  for(long i=2;i<=N;i++)
  {
    long p=i*i;
    while(p<=R)
    {
      st.insert(p);
      p=p*i;
    }
  }
}
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  precal();
  v.assign(st.begin(),st.end());
  v.push_back(R+1);

  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    int tmp=upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a);
    //cout<<tmp<<endl;
    long ans=(((fac[tmp+tmp]*bigmod(fac[tmp+1],mod-2,mod))%mod)*bigmod(fac[tmp],mod-2,mod))%mod;
    if(tmp==0)ans=0;
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}