/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2019 12:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 8800 KB                              
*  problem: https://codeforces.com/contest/1203/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
#define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<setw(2)<<x<<" ";
  cerr<<")"<<endl;
}
 const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;multiset<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  for(int i=1;i<=N;i++)
  {
    auto it=st.lower_bound(i-1);
    if(it==st.end())continue;
    if(abs(*it-i)<=1)st.erase(it);
  }
  cout<<n-st.size()<<endl;
  return 0;
}