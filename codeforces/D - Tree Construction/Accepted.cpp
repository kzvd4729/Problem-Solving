/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2018 19:34                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 6600 KB                              
*  problem: https://codeforces.com/contest/675/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x;
set<pair<int,int> >st;
set<pair<int,int> >::iterator it1,it2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(st.size()==0)
    {
      st.insert({x,i});
      continue;
    }
    it1=st.upper_bound({x,-1});
    if(it1==st.begin())cout<<it1->first<<" ";
    else
    {
      it2=it1;
      it2--;
      if(it1==st.end())cout<<it2->first<<" ";
      else
      {
        if(it1->second>it2->second)cout<<it1->first<<" ";
        else cout<<it2->first<<" ";
      }
    }
    st.insert({x,i});
  }
  return 0;
}