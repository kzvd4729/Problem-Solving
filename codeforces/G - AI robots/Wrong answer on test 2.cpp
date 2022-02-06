/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2019 14:26                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1045/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;map<int,Ordered_Set>mp;
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
    int x,r,q;cin>>x>>r>>q;
    for(int j=q-k;j<=q+k;j++)
    {
      if(!mp.count(j))continue;
      ans+=mp[j].size();
      ans-=mp[j].order_of_key(x-r);
    }
    mp[q].insert(x+r);
  }
  cout<<ans<<endl;
  return 0;
}