/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1007/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=2e9;
int n,arr[N+2];
set<pair<int,int> >st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    st.insert({arr[i],i});
  }
  sort(arr+1,arr+n+1);
  st.insert({inf,0});
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    pair<int,int>tmp=*st.upper_bound({arr[i],inf});
    if(tmp.first==inf)continue;
    ans++;
    st.erase(tmp);
  }
  cout<<ans<<endl;
  return 0;
}