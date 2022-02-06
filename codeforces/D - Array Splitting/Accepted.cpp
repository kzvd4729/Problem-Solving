/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2019 20:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/1175/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;long sum=0;
  for(int i=1;i<=n;i++)cin>>aa[i],sum+=(aa[i]*1LL)*k;
  long qm=0;multiset<long>st;
  for(int i=1;i<n;i++)
    qm+=aa[i],st.insert(qm);
  for(int i=1;i<k;i++)
  {
    sum-=*st.begin();
    st.erase(st.begin());
  }
  cout<<sum<<endl;
  return 0;
}