/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2019 00:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/1166/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
Ordered_Set st;
const int N=1e6;
vector<int>v;
int range(int lo,int hi)
{
  int id1=st.order_of_key(lo);
  int id2=st.order_of_key(hi+1);
  return id2-id1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;v.resize(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  long ans=0;
  for(int i=n-1;i>=0;i--)
  {
    int z=abs(v[i])*2;
    int x=(abs(v[i])+1)/2;
    ans+=(range(-z,-x)*1LL);
    ans+=(range(x,z)*1LL);
    st.insert(v[i]);
  }
  cout<<ans<<endl;
  return 0;
}