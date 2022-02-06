/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 20:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1389/problem/C
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
    string s;cin>>s;
    int ans=0;
    for(char i='0';i<='9';i++)
    {
      int cnt=0;
      for(auto x:s)cnt+=(x==i);
      ans=max(ans,cnt);
    }
    for(char i='0';i<='9';i++)
    {
      for(char j='0';j<='9';j++)
      {
        char a[2];a[0]=i;a[1]=j;
        int f=0,cnt=0;
        for(auto x:s)
        {
          if(x==a[f])cnt++,f^=1;
        }
        cnt-=f;ans=max(ans,cnt);
      }
    }
    cout<<s.size()-ans<<"\n";
  }
  return 0;
}