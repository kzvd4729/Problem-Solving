/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2018 01:37                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 374 ms                                          memory_used: 12600 KB                             
*  problem: https://codeforces.com/contest/356/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int ans[N+2],n,m,l,r,x;
set<int>st;
set<int>::iterator lo,hi,it;
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n+1;i++)st.insert(i);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d%d",&l,&r,&x);
    lo=st.lower_bound(l);
    hi=st.upper_bound(r);
    it=lo;
    while(true)
    {
      if(*lo>*hi)break;
      if(lo==hi)break;
      if(*lo!=x&&!ans[*lo])ans[*lo]=x;
      lo++;
    }
    st.erase(it,hi);
    st.insert(x);
  }
  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
  printf("\n");
  return 0;
}