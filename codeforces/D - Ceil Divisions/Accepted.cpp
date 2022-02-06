/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 13:22                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1469/problem/D
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
  int ck(int a,int b)
{
  int cnt=0;
  while(true)
  {
    if(a>b)swap(a,b);
    if(a==1 && b==2)return cnt;
     if(cnt>20)return cnt;
     b=(b+a-1)/a;cnt++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     int mx=inf,id;
    for(int i=2;i<=min(1000,n-1);i++)
    {
      int g=ck(n,i);
      if(g<mx)mx=g,id=i;
    }
    //if(mx>7)assert(0);
     vector<pair<int,int> >v;
     for(int i=2;i<n;i++)
    {
      if(i==id)continue;
      v.push_back({i,n});
    }
     pair<int,int>a={id,id},b={n,n};
     while(true)
    {
      if(a>b)swap(a,b);
      if(a.first==1 && b.first==2)break;
       v.push_back({b.second,a.second});
      b.first=(b.first+a.first-1)/a.first;
    }
    cout<<(int)v.size()<<'\n';
    for(auto x:v)cout<<x.first<<" "<<x.second<<'\n';
  }
  return 0;
}