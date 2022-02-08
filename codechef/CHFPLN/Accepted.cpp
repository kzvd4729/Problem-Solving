/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2021 20:06:28                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 15.6M                                
*  problem: https://www.codechef.com/COOK131A/problems/CHFPLN
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
const int N=2e5,inf=1e9,mod=1e9+7;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=N;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;cnt[x]++;
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {
      ans+=min(i-1,cnt[i]);
    }
    cout<<ans<<endl;
  }
    return 0;
}