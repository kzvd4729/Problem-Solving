/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/04/2020 23:02                        
*  solution_verdict: Wrong answer on test 46                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1422/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
   char ls='^';string nw;
  vector<int>sz;vector<string>ans;
  for(int i=n-1;i>=0;i--)
  {
    if(nw.size()==0)nw.push_back(s[i]);
    else
    {
      if(s[i]==nw.back())
      {
        if(ls<s[i])nw.pop_back();
        else nw.push_back(s[i]);
      }
      else
      {
        ls=nw.back();nw.push_back(s[i]);
      }
    }
    sz.push_back(nw.size());
    if(nw.size()<=10)
    {
      string tmp=nw;
      reverse(tmp.begin(),tmp.end());
      ans.push_back(tmp);
    }
    else
    {
      string tmp;
      for(int j=nw.size()-1;j>nw.size()-6;j--)
        tmp.push_back(nw[j]);
      tmp.push_back('.');tmp.push_back('.');tmp.push_back('.');
      tmp.push_back(nw[1]);tmp.push_back(nw[0]);
      ans.push_back(tmp);
    }
  }
  for(int i=ans.size()-1;i>=0;i--)
    cout<<sz[i]<<" "<<ans[i]<<'\n';
  return 0;
}