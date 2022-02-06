/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2018 19:54                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 763 ms                                          memory_used: 47200 KB                             
*  problem: https://codeforces.com/contest/459/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> order_set;
const int N=1e6;
order_set st;
map<int,int>mp;
int arr[N+2],n,str[N+2],ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=n;i>=1;i--)
  {
    mp[arr[i]]++;
    str[i]=mp[arr[i]];
    st.insert({str[i],i});
  }
  mp.clear();
  for(int i=1;i<=n;i++)
  {
    mp[arr[i]]++;
    st.erase({str[i],i});
    ans+=st.order_of_key({mp[arr[i]],0});
  }
  cout<<ans<<endl;
  return 0;
}