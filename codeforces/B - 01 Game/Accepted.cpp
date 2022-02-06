/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1373/problem/B
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int o=0,z=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='0')z++;
      else o++;
    }
    int mn=min(o,z);
    if(mn%2)cout<<"DA\n";
    else cout<<"NET\n";
  }
   return 0;
}