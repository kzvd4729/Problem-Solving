/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 10:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1333/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>aa(n+2),cp(n+2,0);
  for(int i=1;i<=n;i++)cin>>aa[i];
  map<long,int>mp;mp[0]=1;long sm=0;
  for(int i=1;i<=n;i++)
  {
    sm+=aa[i];cp[i]=mp[sm];
    mp[sm]=i+1;
  }
  multiset<int>st;long ans=0;
  for(int i=1;i<=n;i++)st.insert(cp[i]);
  //for(int i=1;i<=n;i++)cout<<cp[i]<<" ";cout<<endl;
  for(int i=n;i>=1;i--)
  {
    int bg=*st.rbegin();ans+=i-bg;
    st.erase(st.find(cp[i]));
  }
  cout<<ans<<endl;
  return 0;
}