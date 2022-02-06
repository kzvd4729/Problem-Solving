/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2018 00:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/605/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>ans[N+2];
struct data
{
  int a,b,c;
}pp[N+2];
bool cmp(data p1,data p2)
{
  if(p1.a!=p2.a)return p1.a<p2.a;
  return p1.b>p2.b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>pp[i].a>>pp[i].b;
    pp[i].c=i;
  }
  sort(pp+1,pp+m+1,cmp);
   stack<pair<int,int> >st;
  int last=1;
  for(int i=1;i<=m;i++)
  {
    if(pp[i].b)
    {
      ans[pp[i].c]={last,last+1};
      last++;
      if(st.size()>m)continue;
      for(int i=1;i<last-1;i++)
        st.push({i,last});
    }
    else
    {
      if(st.size()==0)cout<<-1<<endl,exit(0);
      ans[pp[i].c]=st.top();st.pop();
    }
  }
  for(int i=1;i<=m;i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  return 0;
}