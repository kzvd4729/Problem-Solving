/****************************************************************************************
*  @author: kzvd4729                                         created: 01-03-2019 20:40:02                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.02 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/MARCH19A/problems/SUBPRNJL
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
Ordered_Set st;
const int N=2e3;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int ans=0;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      memset(fr,0,sizeof(fr));st.clear();
      for(int j=i;j<=n;j++)
      {
        fr[aa[j]]++;st.insert({aa[j],j});
        int ln=(j-i+1);int m=(k+ln-1)/ln;
        int el=(k+m-1)/k;if(el>ln)assert(0);
        pair<int,int>p=*st.find_by_order(el-1);
        int oc=fr[p.first];if(fr[oc])ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}