/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 11:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/526/problem/A
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
  int n;cin>>n;string s;cin>>s;
   for(int i=0;i<n;i++)
  {
    int f=0;if(s[i]=='.')continue;
    for(int d=1;d<=n;d++)
    {
      if(i+d>=n||s[i+d]=='.')continue;
      if(i+2*d>=n||s[i+2*d]=='.')continue;
      if(i+3*d>=n||s[i+3*d]=='.')continue;
      if(i+4*d>=n||s[i+4*d]=='.')continue;
      cout<<"yes"<<endl,exit(0);
    }
  }
  cout<<"no"<<endl;
  return 0;
}