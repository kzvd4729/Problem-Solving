/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2021 18:12                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 93 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1495/problem/A
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    vector<int>a,b;
    for(int i=1;i<=n+n;i++)
    {
      int x,y;cin>>x>>y;
      if(y==0)a.push_back(abs(x));
      else b.push_back(abs(y));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
     double ans=0;
    for(int i=0;i<n;i++)ans+=sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i]);
    cout<<setprecision(10)<<fixed<<ans<<endl;
  }
   return 0;
}