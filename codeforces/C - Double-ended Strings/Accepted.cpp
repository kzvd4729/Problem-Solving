/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1506/problem/C
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
const int N=1e6,inf=1e9,mod=998244353;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;
     int ans=0;
    for(int l=1;l<=20;l++)
    {
      for(int i=0; ;i++)
      {
        if(i+l-1>=(int)a.size())break;
        for(int j=0; ;j++)
        {
          if(j+l-1>=(int)b.size())break;
           if(a.substr(i,l)==b.substr(j,l))
            ans=max(ans,l);
        }
      }
    }
    cout<<a.size()+b.size()-ans*2<<endl;
  }
  return 0;
}