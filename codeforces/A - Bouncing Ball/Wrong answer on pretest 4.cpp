/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2020 13:19                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1456/problem/A
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
    int n,p,k;cin>>n>>p>>k;
    string s;cin>>s;s="#"+s;
     int x,y;cin>>x>>y;int ans=2e9+2;
    for(int st=p;st<p+k&&st<=n;st++)
    {
      int now=(st-p)*y;
      for(int i=st;i<=n;i+=k)
      {
        if(s[i]=='0')now+=x;
      }
      ans=min(ans,now);
    }
    cout<<ans<<endl;
  }
    return 0;
}