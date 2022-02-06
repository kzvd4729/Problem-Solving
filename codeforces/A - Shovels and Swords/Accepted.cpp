/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 20:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1366/problem/A
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
    int a,b;cin>>a>>b;if(a>b)swap(a,b);
    if(b>=a+a){cout<<a<<endl;continue;}
     int ans=b-a;a-=ans;
    ans+=(a/3)*2;a%=3;if(a==2)ans++;
    cout<<ans<<endl;
  }
    return 0;
}