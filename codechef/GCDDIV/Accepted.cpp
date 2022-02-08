/****************************************************************************************
*  @author: kzvd4729                                         created: 28-04-2018 20:03:25                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/LTIME59A/problems/GCDDIV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,gcd,x,t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    gcd=0;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      gcd=__gcd(gcd,x);
    }
    long sq=sqrt(gcd);
    sq=min(sq+1,k);
    for(int i=2;i<=sq;i++)
      while(gcd%i==0)
        gcd/=i;
    if(gcd<=k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}