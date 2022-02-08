/****************************************************************************************
*  @author: kzvd4729                                         created: 16-07-2018 01:08:10                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 92M                                  
*  problem: https://www.codechef.com/JULY18A/problems/NMNMX
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const long long N=5e6;
long long t,n,k,arr[N+2],ans;
long long fac[N+2];
void factorial(void)
{
  fac[0]=1LL;
  for(long long i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
}
long long bigmod(  long long a, long long p, long long m )
{
    if ( p == 0 )return 1LL; // If power is 0, then a ^ 0 = 1 for any value of a
        , And 1 Mod m=1 for any value of m, So return 1
    if ( p % 2 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left 
        and right child respectively.
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else //If power is even then split it equally and return the result...
    {
        long long c = bigmod ( a, p / 2, m );
        return ( (c%m) * (c%m) ) % m;
    }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  factorial();
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    ans=1LL;
    for(long long i=1;i<=n;i++)
    {
      long long npr,ncr;
      npr=(fac[n-1]*bigmod(fac[n-1-(k-1)],mod-2,mod))%mod;
      ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
      long long tmp=ncr;
      long long sm=i-1;
      long long bg=n-i;
      if(k-1<=sm)
      {
        npr=(fac[sm]*bigmod(fac[sm-(k-1)],mod-2,mod))%mod;
        ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
        tmp=(tmp-ncr+mod)%mod;
      }
      if(k-1<=bg)
      {
        npr=(fac[bg]*bigmod(fac[bg-(k-1)],mod-2,mod))%mod;
        ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
        tmp=(tmp-ncr+mod)%mod;
      }
      ans=(ans*bigmod(arr[i],tmp,mod))%mod;
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}