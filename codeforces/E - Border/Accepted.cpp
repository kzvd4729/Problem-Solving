/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 16:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/1011/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
long n,k,x,gcd;
set<long>st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    gcd=__gcd(gcd,x);
  }
  //if(k%gcd)cout<<0<<endl,exit(0);
  for(long i=0;i<k;i++)
    st.insert((gcd*i)%k);
  cout<<st.size()<<endl;
  while(st.size())
  {
    cout<<*st.begin()<<" ";
    st.erase(*st.begin());
  }
  return 0;
}