/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2019 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 14300 KB                             
*  problem: https://codeforces.com/contest/737/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,s;cin>>n>>s;set<int>st;int ans=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    if(i==s)
    {
      if(aa[i])ans++;
      continue;
    }
    if(aa[i]==0)aa[i]=1e6;
    fr[aa[i]]++;
    st.insert(aa[i]);
  }
  for(int i=1; ;i++)
  {
    if(st.size()==0)break;
    if(*st.begin()==i)st.erase(*st.begin());
    else
    {
      ans++;
      int ed=*st.rbegin();fr[ed]--;
      if(fr[ed]==0)st.erase(ed);
    }
  }
  cout<<ans<<endl;
  return 0;
}