/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/29/2019 00:15                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1283/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)cin>>aa[i],vis[aa[i]]=1;
   set<pair<int,int> >st;cout<<n<<endl;
  for(int i=1;i<=n;i++)if(!vis[i])st.insert({i,i});
  for(int i=n;i>1;i--)
  {
    pair<int,int>p=*st.begin();st.erase(p);
    cout<<aa[i]<<" "<<p.second<<"\n";
    st.insert({max(aa[i],p.first),aa[i]});
  }
  return 0;
}