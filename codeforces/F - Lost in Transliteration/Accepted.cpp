/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 20:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/883/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<string>st;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;vector<char>tmp;
    for(auto x:s)
    {
      if(x=='h')
      {
        while(tmp.size()&&tmp.back()=='k')
          tmp.pop_back();
        tmp.push_back(x);
      }
      else if(x=='u')
      {
        tmp.push_back('o');
        tmp.push_back('o');
      }
      else tmp.push_back(x);
    }
    string kk;
    for(auto z:tmp)
      kk.push_back(z);
    //cout<<kk<<endl;
    st.insert(kk);
  }
  cout<<st.size()<<endl;
  return 0;
}