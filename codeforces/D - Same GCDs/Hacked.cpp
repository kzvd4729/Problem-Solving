/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2020 21:39                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 1575 ms                                         memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/1295/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=1e9;
 long isPrime[N+2];vector<long>prime;
void seive(long n)
{
  prime.push_back(2);isPrime[1]=1;
  for(long i=4;i<=n;i+=2)isPrime[i]=1;
  long sq=sqrt(n+1);
  for(long i=3;i<=n;i+=2)
  {
    if(isPrime[i])continue;prime.push_back(i);
    if(i>sq)continue;
    for(long j=i*i;j<=n;j+=2*i)
      isPrime[j]=1;
  }
}
long mb(long n)
{
  long cnt=0;
  for(auto x:prime)
  {
    if(n%x)continue;if(n%(1LL*x*x)==0)return 0;
    n/=x;cnt++;
  }
  if(n>1)cnt++;
  if(cnt%2==0)return 1;else return -1;
}
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
long ret(long m,long r)
{
  if(r<=0)return 0;
  long ans=0;
  vector<long>v=divisors(m);
   for(auto x:v)
  {
    //cout<<x<<" "<<mb(x)<<endl;
    ans+=mb(x)*(r/x);
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);
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