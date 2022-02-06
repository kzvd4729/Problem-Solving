/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2018 01:32                        
*  solution_verdict: Compilation error                       language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
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
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)st.insert(i);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d%d",&l,&r,&x);
//    lo=lower_bound(st.begin(),st.end(),l);
//    hi=upper_bound(st.begin(),st.end(),r);
    lo=st.lower_bound(l);
    hi=st.upper_bound(r);
//    for(set<int>::iterator it=lo;it!=hi;it++)if(*it!=x&&!ans[*it])ans[*it]=x;
    while(true)
    {
      if(lo>hi)break;
      if(lo==hi)break;
      if(*lo!=x&&!ans[*lo])ans[*lo]=x;
      lo++;
    }
    st.erase(lo,hi);
    st.insert(x);
  }
  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
  printf("\n");
  return 0;
}