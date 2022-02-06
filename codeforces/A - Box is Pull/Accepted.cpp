/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 14:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1428/problem/A
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
    int a,b,c,d;cin>>a>>b>>c>>d;
    int ans=abs(a-c)+abs(b-d);
     if(a==c||b==d)cout<<ans<<endl;
    else cout<<ans+2<<endl;
  }
    return 0;
}