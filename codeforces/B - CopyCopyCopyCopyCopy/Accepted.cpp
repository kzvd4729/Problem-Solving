/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/14/2020 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 3200 KB                              
*  problem: https://codeforces.com/contest/1325/problem/B
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
    int n;cin>>n;set<int>st;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;st.insert(x);
    }
    cout<<st.size()<<endl;
  }
  return 0;
}