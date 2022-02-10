/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-13 23:19:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 31                                         memory_used (MB): 1.1                             
*  problem: https://vjudge.net/problem/URAL-1028
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
const int inf=1e8;

typedef tree<pair<int,int>,null_type,less<pair<int,int> >,
rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ordered_set st;
int n,x,y,level[15003];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x>>y;
    int id=st.order_of_key({x,inf});
    level[id]++;
    st.insert({x,i});
  }
  for(int i=0;i<n;i++)
    cout<<level[i]<<"\n";
  return 0;
}