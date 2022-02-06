/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/19/2020 18:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 61 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/794/problem/A
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
const int N=50;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c;cin>>a>>b>>c;
  int n;cin>>n;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(x>b&&x<c)cnt++;
  }
  cout<<cnt<<endl;
   return 0;
}