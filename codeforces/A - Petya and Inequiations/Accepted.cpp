/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2020 14:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/111/problem/A
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
void no()
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,x,y;cin>>n>>x>>y;
  if(y<n)no();
   long mx=1LL*(y-(n-1))*(y-(n-1))+(n-1);
  if(mx<x)no();
  for(int i=1;i<n;i++)cout<<1<<" ";
  cout<<y-(n-1)<<endl;
     return 0;
}