/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 20:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1374/problem/C
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
    int n;cin>>n;
    string s;cin>>s;int bl=0,ans=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='(')bl++;else bl--;
      if(bl<ans)ans=bl;
    }
    cout<<abs(ans)<<endl;
  }
  return 0;
}