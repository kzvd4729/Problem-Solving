/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 10400 KB                             
*  problem: https://codeforces.com/contest/1165/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
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
  int ans=1;
  while(st.size())
  {
    int x=*st.begin();
    if(x>=ans)
      ans++;
    st.erase(st.find(x));
  }
  cout<<ans-1<<endl;
  return 0;
}