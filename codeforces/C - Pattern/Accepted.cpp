/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2019 13:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/412/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
  string ans;
  for(int j=0;j<s[0].size();j++)
  {
    set<char>st;
    for(int i=0;i<n;i++)
    {
      if(s[i][j]=='?')continue;
      st.insert(s[i][j]);
    }
    if(st.size()>1)ans.push_back('?');
    else if(st.size()==1)ans.push_back(*st.begin());
    else ans.push_back('a');
  }
  cout<<ans<<endl;
  return 0;
}