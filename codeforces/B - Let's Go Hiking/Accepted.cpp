/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2021 20:37                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/1495/problem/B
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
 int a[N+2],lt[N+2],rt[N+2],mlt[N+2],mrt[N+2],ea[N+2],eb[N+2],mea[N+2],meb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   rt[n]=0;
  for(int i=n-1;i>=1;i--)
  {
    if(a[i]>a[i+1])rt[i]=rt[i+1]+1;
    else rt[i]=0;
  }
  eb[n]=0;
  for(int i=n-1;i>=1;i--)
  {
    if(a[i]<a[i+1])eb[i]=eb[i+1]+1;
    else eb[i]=0;
  }
   lt[1]=0;
  for(int i=2;i<=n;i++)
  {
    if(a[i]>a[i-1])lt[i]=lt[i-1]+1;
    else lt[i]=0;
  }
  ea[1]=0;
  for(int i=2;i<=n;i++)
  {
    if(a[i]<a[i-1])ea[i]=ea[i-1]+1;
    else ea[i]=0;
  }
   mlt[1]=lt[1];
  for(int i=2;i<=n;i++)mlt[i]=max(lt[i],mlt[i-1]);
  mea[1]=ea[1];
  for(int i=2;i<=n;i++)mea[i]=max(ea[i],mea[i-1]);
    mrt[n]=rt[n];
  for(int i=n-1;i>=1;i--)mrt[i]=max(rt[i],mrt[i+1]);
  meb[n]=eb[n];
  for(int i=n-1;i>=1;i--)meb[i]=max(eb[i],meb[i+1]);
   int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(lt[i]==0||rt[i]==0)continue;
    int y,a,b,x=i,f;
     f=0;
    y=x-lt[i];
    if(abs(x-y)%2==0)f=1;
    if(rt[i]>abs(x-y))f=1;
    if(f==0)continue;
      if(lt[i]>1)
    {
      f=0;
      y=x-lt[i]+1;
      if(abs(x-y)%2==0)f=1;
      if(rt[i]>abs(x-y))f=1;
      if(f==0)continue;
    }
     f=0;
    y=x+rt[i];
    if(abs(x-y)%2==0)f=1;
    if(lt[i]>abs(x-y))f=1;
    if(f==0)continue;
      if(rt[i]>1)
    {
      f=0;
      y=x+rt[i]-1;
      if(abs(x-y)%2==0)f=1;
      if(lt[i]>abs(x-y))f=1;
      if(f==0)continue;
    }
     int mx=0;
    mx=max(mx,mlt[x-lt[i]-1]);
    mx=max(mx,mea[x-lt[i]]);
    mx=max(mx,mrt[x+rt[i]+1]);
    mx=max(mx,meb[x+rt[i]]);
     if(max(lt[i],rt[i])>mx)ans++;
   }
  cout<<ans<<endl;
  return 0;
}