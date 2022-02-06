/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2021 12:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 16000 KB                             
*  problem: https://codeforces.com/contest/1552/problem/C
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
  int a[N+2],b[N+2],vs[N+2];
 int main()              
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
     for(int i=1;i<=n+n;i++)vs[i]=0;
    for(int i=1;i<=k;i++)cin>>a[i]>>b[i],vs[a[i]]=vs[b[i]]=1;
     vector<int>v;
    for(int i=1;i<=n+n;i++)if(vs[i]==0)v.push_back(i);
     int hf=((int)v.size())/2;
    for(int i=0;i<hf;i++)
    {
      ++k;
      a[k]=v[i],b[k]=v[hf+i];
    }
    for(int i=1;i<=k;i++)if(a[i]>b[i])swap(a[i],b[i]);
     //for(int i=1;i<=k;i++)cout<<a[i]<<" "<<b[i]<<endl;
     int ans=0;
    for(int i=1;i<=k;i++)
    {
      for(int j=1;j<i;j++)
      {
        if(a[j]>a[i] && a[j]<b[i] && b[j]>a[i] && b[j]<b[i])continue;
        if((a[j]<a[i] || a[j]>b[i]) && (b[j]<a[i] || b[j]>b[i]))continue;
        ans++;
      }
    }
    cout<<ans<<endl;
  }
    return 0;
}