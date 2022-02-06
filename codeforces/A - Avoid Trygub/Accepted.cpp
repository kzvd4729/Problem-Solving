/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2020 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1450/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    string s,p;cin>>s;int a=0,b=0;
    for(auto x:s)
    {
      if(x=='t')a++;
      else if(x=='b')b++;
      else p.push_back(x);
    }
    for(int i=1;i<=b;i++)p.push_back('b');
    for(int i=1;i<=a;i++)p.push_back('t');
    cout<<p<<'\n';
  }
    return 0;
}