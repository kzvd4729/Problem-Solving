/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/01/2020 20:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 124 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1371/problem/E1
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);int mn=a[1];
    int cr=mn;
  for(int i=1;i<=n;i++)
  {
    if(cr>=a[i])cr++;
    else {mn+=a[i]-cr;cr=a[i]+1;}
  }
  vector<int>ans;//cout<<mn<<endl;
  for(int i=mn;i<=2000;i++)
  {
    int f=0;
    for(int j=1;j<=n;j++)
    {
      int id=upper_bound(a+1,a+n+1,i+j-1)-a;
      //cout<<"*"<<id-j<<endl;
      if((id-j)%p==0)f=1;
    }
    if(!f)ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";cout<<endl;
  return 0;
}