/****************************************************************************************
*  @author: kzvd4729                                         created: 01-06-2021 18:21:55                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/TRTOKENS
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
const int N=1e6,inf=1e9,mod=1000000007;
int p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;s="#"+s;
    for(int i=2;i<=n;i++)cin>>p[i];
    int cnt=0,f=1;
    while(f)
    {
      f=0;
      for(int i=2;i<=n;i++)
      {
        if(s[i]=='1' && s[p[i]]=='0')
        {
          f=1;cnt++;
          s[i]='0';s[p[i]]='1';
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}