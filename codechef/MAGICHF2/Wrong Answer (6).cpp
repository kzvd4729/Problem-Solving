/****************************************************************************************
*  @author: kzvd4729                                         created: 04-11-2018 15:36:15                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/NOV18A/problems/MAGICHF2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;double ans=0;
  while(t--)
  {
    long n,k;cin>>n>>k;
    if(n==2)
    {
      //cout<<2<<endl;
      ans=1.0/2.0;
      cout<<setprecision(6)<<fixed<<ans<<endl;
      continue;
    }
    while(k--)
    {
      if(n==2)n=1;
      if(n==1)break;
      long a=n/2;long b=n-a;
      if(b>a)swap(a,b);
      if(a%2&&b%2)a++;
      n=a;
    }
    //cout<<n<<endl;
    ans=1.0/(n*1.0);
    cout<<setprecision(6)<<fixed<<ans<<endl;
  }
  return 0;
}