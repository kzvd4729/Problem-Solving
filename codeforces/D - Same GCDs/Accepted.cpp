/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/30/2020 15:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 624 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1295/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=1e9;
 vector<long>divisors(long x)
{
  long sq=sqrt(x+1);vector<long>ret;
  for(long i=1;i<=sq;i++)
  {
    if(x%i)continue;ret.push_back(i);
    if(i!=x/i)ret.push_back(x/i);
  }
  sort(ret.begin(),ret.end());
  return ret;
}
long mb(long n,vector<long>v)
{
  long cnt=0;
  for(auto x:v)
  {
    if(x==1)continue;
    if(n%x)continue;if(n%(1LL*x*x)==0)return 0;
    n/=x;cnt++;
  }
  if(n>1)cnt++;
  if(cnt%2==0)return 1;else return -1;
}
long ret(long m,long r)
{
  if(r<=0)return 0;
  long ans=0;
  vector<long>v=divisors(m);
   for(auto x:v)
  {
    //cout<<x<<" "<<mb(x)<<endl;
    ans+=mb(x,v)*(r/x);
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long a,m;cin>>a>>m;long g=__gcd(a,m);
    long lt=a,rt=a+m-1;
     m/=g,lt/=g,rt/=g;
    //cout<<lt<<" "<<rt<<" "<<m<<endl;
    cout<<ret(m,rt)-ret(m,lt-1)<<"\n";
   }
  return 0;
}