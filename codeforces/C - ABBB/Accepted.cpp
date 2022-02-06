/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 14:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1428/problem/C
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
const int N=1e6;
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s,p;cin>>s;
    for(int i=0;i<s.size();i++)
    {
      if(p.size()==0)p.push_back(s[i]);
      else
      {
        if(s[i]=='A')p.push_back(s[i]);
        else p.pop_back();
      }
    }
    cout<<p.size()<<'\n';
  }
  return 0;
}