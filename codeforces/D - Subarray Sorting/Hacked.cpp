/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 21:32                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/1187/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
    int pt=0,f=0;multiset<int>st;st.insert(1e9);
    for(int i=1;i<=n;i++)
    {
      while(true)
      {
        int vl=*st.begin();
        if(vl==bb[i])break;
        if(vl<bb[i]){f=1;break;}
        ++pt;if(pt>n){f=1;break;}
        st.insert(aa[pt]);
      }
      if(f)break;
      int vl=*st.begin();
      st.erase(st.find(vl));
    }
    if(f)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}