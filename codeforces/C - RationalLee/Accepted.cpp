/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/23/2020 20:39                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 15600 KB                             
*  problem: https://codeforces.com/contest/1369/problem/C
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
int a[N+2],b[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;long ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
    for(int i=1;i<=k;i++)cin>>b[i];sort(b+1,b+k+1);
    for(int i=1;i<=n;i++)vs[i]=0;
    int cnt=0;
    for(int i=1;i<=k;i++)cnt+=(b[i]==1);
     int p=1;
    for(int i=k;i>=1;i--)
    {
      p++;
      while(b[i]>2)
      {
        vs[p++]=1;b[i]--;
      }
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    for(int i=n;i>=1;i--)
    {
      if(vs[i])continue;
      ans+=a[i];
      if(cnt)ans+=a[i],cnt--;
    }
    cout<<ans<<endl;
  }
  return 0;
}