/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 22:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/1042/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<long,long>,null_type,less<pair<long,long> >,rb_tree_tag,tree_order_statistics_node_update>order_set;
order_set st;
 const long N=2e5;
long arr[N+2],ans,qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  for(long i=1;i<=n;i++)
  {
    qm[i]=qm[i-1]+arr[i];
    st.insert({qm[i],i});
  }
  for(long i=1;i<=n;i++)
  {
    ans+=st.order_of_key(make_pair(k+qm[i-1],-1));
    st.erase({qm[i],i});
  }
  cout<<ans<<endl;
  return 0;
}