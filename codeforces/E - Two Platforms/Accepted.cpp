/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/04/2020 21:17                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 171 ms                                          memory_used: 13600 KB                             
*  problem: https://codeforces.com/contest/1409/problem/E
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
const int N=1e6;
int a[N+2],b[N+2],c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
     vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(a[i]);
    sort(v.begin(),v.end());
     for(int i=0;i<n;i++)
    {
      c[i]=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
      c[i]-=i;
    }
    c[n]=0;
    for(int i=n-1;i>=0;i--)c[i]=max(c[i],c[i+1]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
      int now=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
      now-=i;
      ans=max(ans,now+c[i+now]);
    }
    cout<<ans<<'\n';
  }
  return 0;
}