/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 22:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1051/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  long l,r;cin>>l>>r;
  cout<<"YES"<<endl;
  for(long i=l;i<=r;i+=2)
    cout<<i<<" "<<i+1<<"\n";
  return 0;
}