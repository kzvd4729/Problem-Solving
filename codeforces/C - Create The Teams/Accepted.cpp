/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 21:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1380/problem/C
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
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);int ans=0,cnt=0;
    for(int i=n;i>=1;i--)
    {
      cnt++;
      if(1LL*cnt*a[i]>=k)ans++,cnt=0;
    }
    cout<<ans<<endl;
  }
    return 0;
}