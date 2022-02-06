/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2020 13:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1456/problem/A
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
const int N=1e5;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,p,k;cin>>n>>p>>k;
    string s;cin>>s;s="#"+s;
     int x,y;cin>>x>>y;
    memset(cnt,0,sizeof cnt);
    for(int st=p;st<p+k&&st<=n;st++)
    {
      for(int i=st;i<=n;i+=k)
        cnt[st-p]+=(s[i]=='0');
    }
    int ans=cnt[0]*x;
    for(int i=p;i<=n;i++)
    {
      int id=(i-p)%k;
      ans=min(ans,cnt[id]*x+(i-p)*y);
       cnt[id]-=(s[i]=='0');
    }
    cout<<ans<<endl;
  }
    return 0;
}