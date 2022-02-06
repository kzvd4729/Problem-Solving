/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 10400 KB                             
*  problem: https://codeforces.com/contest/1157/problem/E
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
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  for(int i=1;i<=n;i++)
  {
    int p=*st.begin();
    auto it=st.lower_bound(n-aa[i]);
    if(it==st.end())
    {
      cout<<(aa[i]+p)%n<<" ";
      st.erase(st.find(p));
      continue;
    }
    if((aa[i]+p)%n<(aa[i]+*it)%n)
    {
      cout<<(aa[i]+p)%n<<" ";
      st.erase(st.find(p));
    }
    else
    {
      cout<<(aa[i]+*it)%n<<" ";
      st.erase(st.find(*it));
    }
  }
  cout<<endl;
  return 0;
}