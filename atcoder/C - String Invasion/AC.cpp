/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-21 15:55:09                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 23 ms                                           memory_used: 3716 KB                              
*  problem: https://atcoder.jp/contests/arc113/tasks/arc113_c
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
const int N=1e6,inf=1e9;
 int cnt[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;
   long ans=0;
  for(int i=(int)s.size()-1;i>0;i--)
  {
    int now=s[i]-'a';
    if(s[i]==s[i-1])
    {
      for(int j=0;j<26;j++)
      {
        if(now==j)continue;
        ans+=cnt[j];cnt[now]+=cnt[j];cnt[j]=0;
      }
      //cout<<ans<<endl;
    }
    cnt[now]++;
  }
  cout<<ans<<endl;
    return 0;
}