/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/10/2021 21:09                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1512/problem/E
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
  int sum(int x)
{
  return (x*(x+1))/2;
}
 int vs[500+2],tk[500+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,l,r,s;cin>>n>>l>>r>>s;
     int m=(r-l+1);
     memset(vs,0,sizeof vs);
    for(int i=n;i>=1;i--)
    {
      if(i>s)continue;
      if(m==0)continue;
       if(sum(m-1)<=s-i)
      {
        vs[i]=1;
        s-=i;m--;
      }
    }
     if(s)
    {
      cout<<-1<<endl;continue;
    }
     memset(tk,0,sizeof tk);
    int now=l-1;
     for(int i=1;i<=n;i++)
    {
      if(now==0)break;
       if(vs[i])continue;
      cout<<i<<" ";tk[i]=1;
      now--;
    }
     for(int i=1;i<=n;i++)if(vs[i])cout<<i<<" ";
     for(int i=1;i<=n;i++)
    {
      if(tk[i] || vs[i])continue;
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}