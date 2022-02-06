/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2019 16:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 9600 KB                              
*  problem: https://codeforces.com/contest/866/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;multiset<int>st;long ans=0;
  while(n--)
  {
    int x;cin>>x;
    if(st.size()==0)
    {
      st.insert(x);
      continue;
    }
    int tp=*st.begin();
    if(tp>=x)st.insert(x);
    else
    {
      ans+=(x-tp);
      st.insert(x);st.insert(x);
      st.erase(st.find(tp));
    }
  }
  cout<<ans<<endl;
  return 0;
}