/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2018 01:06                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++17                               
*  run_time: 3000 ms                                         memory_used: 12600 KB                             
*  problem: https://codeforces.com/contest/356/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int ans[N+2],n,m,l,r,x;
set<int>st;
set<int>::iterator lo,hi;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)st.insert(i);
  for(int i=1;i<=m;i++)
  {
    cin>>l>>r>>x;
    lo=lower_bound(st.begin(),st.end(),l);
    hi=upper_bound(st.begin(),st.end(),r);
    while(true)
    {
      if(lo==hi)break;
      if(*lo!=x&&!ans[*lo])ans[*lo]=x;
      lo++;
    }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}