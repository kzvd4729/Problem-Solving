/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 20:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/1100/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int cnt=0;
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
    st.insert({0,i});
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;fr[x]++;
    st.erase({fr[x]-1,x});
    st.insert({fr[x],x});
    if(st.begin()->first>cnt)
    {
      cout<<'1';cnt++;
    }
    else cout<<'0';
  }
  cout<<endl;
  return 0;
}