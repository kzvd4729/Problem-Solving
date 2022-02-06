/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2021 23:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1389/problem/E
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
 vector<int>dd(int x,int mn)
{
  int sq=sqrt(x+1);vector<int>v;
  for(int i=1;i<=sq;i++)
  {
    if((x%i)==0)v.push_back(i),v.push_back(x/i);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int m,d,w;cin>>m>>d>>w;
    vector<int>v=dd(w,min(m,d));
     int f=inf;
    for(auto x:v)
    {
      if(w%x)continue;
      if((1LL*x*d)%w==(x%w))f=min(f,x);
    }
    if(f>=min(d,m))
    {
      cout<<0<<endl;continue;
    }
    int mn=min(d,m);
    int bg=mn%f+1;
     //cout<<f<<endl;
     int sm=(mn-bg)/f;
    long ans=(1LL*sm*(sm+1))/2;
    ans*=f;
     ans+=1LL*(sm+1)*(bg-1);
     cout<<ans<<endl;
  }
  return 0;
}