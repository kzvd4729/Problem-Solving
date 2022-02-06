/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 10:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1388/problem/A
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
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    if(n<=30)cout<<"NO\n";
    else
    {
      int rm=n-30;
      if(rm==6||rm==10||rm==14)
        cout<<"YES 6 10 15 "<<n-31<<'\n';
      else cout<<"YES 6 10 14 "<<n-30<<'\n';
    }
  }
  return 0;
}