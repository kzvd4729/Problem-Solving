/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 12:51                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1394/problem/B
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
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,d,m;cin>>n>>d>>m;int a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x<=m)aa[++a]=x;
    else bb[++b]=x;
  }
  sort(aa+1,aa+a+1);sort(bb+1,bb+b+1,greater<int>());
  for(int i=1;i<=n;i+=d+1)vis[i]=1;
  int cnt=0;
  for(int i=1;i<=b;i++)cnt+=vis[i];
   long ans=0;
  for(int i=1;i<=n;i++)ans+=aa[i];
  for(int i=1;i<=cnt;i++)ans+=bb[i];
   long now=ans;
  for(int i=1;i<=a;i++)
  {
    now-=aa[i];b++;
    if(vis[b])now+=bb[++cnt];
     ans=max(ans,now);
  }
  cout<<ans<<endl;
    return 0;
}