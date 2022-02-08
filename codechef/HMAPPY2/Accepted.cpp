/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 15:26:04                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/HMAPPY2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,a,b,k;cin>>n>>a>>b>>k;
    long gc=__gcd(a,b);
    long lcm=(a*b)/gc;
    long sum=n/a+n/b-2*(n/lcm);
    if(sum>=k)cout<<"Win"<<endl;
    else cout<<"Lose"<<endl;
    //cout<<sum<<endl;
      }
  return 0;
}