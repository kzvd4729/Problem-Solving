/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 22:26                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1406/problem/B
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
 int a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     vector<int>ng,ps;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      if(a[i]<0)ng.push_back(a[i]);
      else ps.push_back(a[i]);
    }
     if(n==5)
    {
      cout<<1LL*a[1]*a[2]*a[3]*a[4]*a[5]<<endl;
      continue;
    }
     sort(ng.begin(),ng.end());
    sort(ps.begin(),ps.end());
     if((int)ps.size()==0)
    {
      long ml=1;
      for(int i=(int)ng.size()-1;i>=(int)ng.size()-5;i--)
        ml*=ng[i];
      cout<<ml<<endl;
      continue;
    }
      long ans=-1LL*inf*inf;
     long ml=1;
    if((int)ps.size()>=5)
    {
      for(int i=(int)ps.size()-1;i>=(int)ps.size()-5;i--)
        ml*=ps[i];
       ans=max(ans,ml);
    }
     ml=1;
    if((int)ps.size()>=3 && (int)ng.size()>=2)
    {
      for(int i=(int)ps.size()-1;i>=(int)ps.size()-3;i--)
        ml*=ps[i];
       for(int i=0;i<2;i++)
        ml*=ng[i];
       ans=max(ans,ml);
    }
     ml=1;
    if((int)ps.size()>=1 && (int)ng.size()>=4)
    {
    //cout<<"HERE"<<endl;
      for(int i=(int)ps.size()-1;i>=(int)ps.size()-1;i--)
        ml*=ps[i];
       for(int i=0;i<4;i++)
        ml*=ng[i];
       ans=max(ans,ml);
    }
      cout<<ans<<endl;
   }
  return 0;
}