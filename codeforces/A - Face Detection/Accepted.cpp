/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/10/2020 13:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/549/problem/A
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
const int N=1e6,inf=1e9;
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
  int cnt=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<m-1;j++)
    {
      string a;
      a.push_back(s[i][j]);a.push_back(s[i][j+1]);
      a.push_back(s[i+1][j]);a.push_back(s[i+1][j+1]);
      sort(a.begin(),a.end());if(a=="acef")cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}