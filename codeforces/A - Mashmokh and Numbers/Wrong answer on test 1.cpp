/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 17:38                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/414/problem/A
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
  int n,k;cin>>n>>k;if(k<n/2)cout<<-1<<endl,exit(0);
   int cnt=1;
  for(int i=1;i<=n/2-1;i++)
    cout<<" "<<++cnt<<" "<<++cnt;
   k-=(n/2-1);
   for(int i=k; ;i+=k)
  {
    if(i>cnt)
    {
      cout<<" "<<i<<" "<<i+k;
      break;
    }
  }
  if(n%2)cout<<" "<<1;cout<<endl;
    return 0;
}