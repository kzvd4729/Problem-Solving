/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2018 16:45                        
*  solution_verdict: Wrong answer on test 46                 language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/762/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
const int N=1e5,R=1e9,F=1e4;
int cnt;ordered_set st[F+2];
struct data
{
  int x,r,f;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.r>B.r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i].x>>arr[i].r>>arr[i].f;
  sort(arr+1,arr+n+1,cmp);
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=max(1,arr[i].f-k);j<=min(F,arr[i].f+k);j++)
    {
      ans+=(st[j].order_of_key(arr[i].x+arr[i].r+1))*1LL;
      ans-=(st[j].order_of_key(arr[i].x-arr[i].r))*1LL;
    }
    st[arr[i].f].insert(arr[i].x);
  }
  cout<<ans<<endl;
  return 0;
}