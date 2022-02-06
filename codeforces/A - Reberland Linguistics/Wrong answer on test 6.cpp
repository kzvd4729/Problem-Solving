/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2019 23:50                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/666/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
string s;int n;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;n=s.size();set<string>st;
  for(int i=5;i<n;i++)
  {
    if(i+1<n)
    {
      string tmp;tmp.push_back(s[i]);
      tmp.push_back(s[i+1]);
      if(n-i-2==1);
      else if(n-i-2==2||n-i-2==4)
      {
        if(s[i]==s[i+2]&&s[i+1]==s[i+3]);
        else st.insert(tmp);
      }
      else st.insert(tmp);
    }
    if(i+2<n)
    {
      string tmp;tmp.push_back(s[i]);
      tmp.push_back(s[i+1]);tmp.push_back(s[i+2]);
      if(n-i-3==1);
      else if(n-i-3==3)
      {
        if(s[i]==s[i+3]&&s[i+1]==s[i+4]&&s[i+2]==s[i+5]);
        else st.insert(tmp);
      }
      else st.insert(tmp);
    }
  }
  cout<<st.size()<<endl;
  for(auto x:st)
    cout<<x<<endl;
  return 0;
}