/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/1114/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;priority_queue<int>pq;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];pq.push(aa[i]);
  }
  multiset<int>st;
  for(int i=1;i<=m*k;i++)
  {
    st.insert(pq.top());pq.pop();
  }
  int cnt=0;long ans=0;vector<int>pr;
  for(int i=1;i<=n;i++)
  {
    if(st.find(aa[i])!=st.end())
    {
      cnt++;st.erase(st.find(aa[i]));
      ans+=(aa[i]*1LL);
    }
    if(cnt==m)
    {
      pr.push_back(i);
      cnt=0;
    }
  }
  cout<<ans<<endl;pr.pop_back();
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}