/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2018 22:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1068/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  set<long>st;long b;cin>>b;
  long sq=sqrt(b+1);
  for(long i=1;i<=sq;i++)
  {
    if(b%i)continue;
    st.insert(i);
    st.insert(b/i);
  }
  cout<<st.size()<<endl;
  return 0;
}