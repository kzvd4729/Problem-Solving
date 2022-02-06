/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 9600 KB                              
*  problem: https://codeforces.com/contest/1373/problem/C
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
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int bl=0;
    for(int i=1;i<=s.size()+1;i++)cnt[i]=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='-')bl++;else bl--;
      if(bl>0)
      {
        if(cnt[bl]==0)cnt[bl]=i+1;
      }
    }
    long ans=0;
    for(int i=1; ;i++)
    {
      if(cnt[i]==0){ans+=s.size();break;}
      ans+=cnt[i];
    }
    cout<<ans<<"\n";
  }
   return 0;
}