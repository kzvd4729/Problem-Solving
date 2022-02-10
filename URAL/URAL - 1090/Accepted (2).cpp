/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-13 23:47:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 124                                        memory_used (MB): 0.8                             
*  problem: https://vjudge.net/problem/URAL-1090
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>ordered_set;
ordered_set st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,k;cin>>n>>k;int mx=-1,ans;
  for(int i=1;i<=k;i++)
  {
    int sum=0;st.clear();
    for(int j=1;j<=n;j++)
    {
      int x;cin>>x;
      sum+=j-st.order_of_key(x)-1;
      st.insert(x);
    }
    if(sum>mx)mx=sum,ans=i;
    //cout<<"--------------"<<sum<<endl;
  }
  cout<<ans<<endl;
  return 0;
}