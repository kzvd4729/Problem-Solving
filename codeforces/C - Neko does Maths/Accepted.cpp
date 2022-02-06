/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2019 21:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1152/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b;cin>>a>>b;if(a<b)swap(a,b);
   if(a==b)
  {
    cout<<0<<endl,exit(0);
  }
   long d=a-b;vector<long>v;
  long sq=sqrt(d+1);
  for(long i=1;i<=sq;i++)
  {
    if(d%i==0)
    {
      v.push_back(i);v.push_back(d/i);
    }
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  long mn=6e18+2,kk=-1;
  for(auto x:v)
  {
    long k=(x-(a%x))%x;
    long lcm=((a+k)*(b+k))/__gcd(a+k,b+k);
    if(lcm<mn)
    {
      mn=lcm;kk=k;
    }
  }
  cout<<kk<<endl;
  return 0;
}