/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 17:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1190/problem/A
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)cin>>a[i];
   int ans=0;long b=1;
  for(int i=1;i<=m; )
  {
    long tm=(a[i]-b)/k;
    b+=tm*k;
     int cnt=0;
    for(int j=i;j<=m;j++)
    {
      if(a[j]>=b+k)break;
      else cnt++;
    }
    ans++;i+=cnt;b+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}