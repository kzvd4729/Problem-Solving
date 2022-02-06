/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 10:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1354/problem/B
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
#define long long long
using namespace std;
const int N=2e5;
int cnt[3+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    auto ck=[&](int l,string s)
    {
      cnt[1]=0,cnt[2]=0,cnt[3]=0;
      for(int i=0;i<s.size();i++)
      {
        cnt[s[i]-'0']++;
        if(i>=l)cnt[s[i-l]-'0']--;
        if(cnt[1]&&cnt[2]&&cnt[3])return true;
      }
      return false;
    };
    int lo=1,hi=s.size(),md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ck(md,s))hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)if(ck(md,s))break;
    if(md>s.size())md=0;cout<<md<<'\n';
  }
  return 0;
}