/****************************************************************************************
*  @author: kzvd4729                                         created: 14-07-2019 17:10:38                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/JULY19A/problems/GUESSPRM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long x1=1000000000-1;
    cout<<1<<" "<<x1<<endl;
    long r;cin>>r;
    long nm1=x1*x1-r;
    long x2=x1+1;
    cout<<1<<" "<<x2<<endl;
    cin>>r;
    long nm2=x2*x2-r;
    cout<<2<<" "<<__gcd(nm1,nm2)<<endl;
    string s;cin>>s;
  }
  return 0;
}