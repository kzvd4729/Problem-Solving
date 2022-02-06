/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 11:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 920 ms                                          memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1342/problem/C
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;int cnt=1,ms=0;
    for(int i=1;i<=N;i++)
    {
      if((i%a)%b==(i%b)%a)
      {
        if(ms)break;
        else cnt++;
      }
      else ms++;
    }
    auto ret=[&](int cnt,int ms,long x)
    {
      x++;
      if(ms==0)return x;
      long d=x/(cnt+ms);long r=cnt*d;
      x-=(cnt+ms)*d;r+=min(x,cnt*1LL);
      return r;
    };
    int q;cin>>q;
    while(q--)
    {
      long l,r;cin>>l>>r;
      cout<<r-l+1-(ret(cnt,ms,r)-ret(cnt,ms,l-1))<<" ";
    }
    cout<<endl;
   }
  return 0;
}