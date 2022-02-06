/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2020 23:57                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 81900 KB                             
*  problem: https://codeforces.com/contest/1271/problem/E
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
const long N=1e7;
long cnt[N+2];
void path(long n)
{
  while(n)
  {
    //cout<<n<<" ";
    cnt[n]++;
    if(n%2==0)n/=2;
    else n--;
  }
  //cout<<endl;
}
long cal(long x,long n)
{
  if(x==n)return 1;
  long l=x,r=x;if(x%2==0)r++;
  long ans=r-l+1;
   while(true)
  {
    l*=2,r=r+r+1;if(l>n)break;r=min(r,n);
    ans+=r-l+1;if(r==n)break;
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;
  /*for(long i=1;i<=n;i++)path(i);
  set<long>st;
  for(long i=1;i<=n;i++)st.insert(cnt[i]);
   long mx=-1;vector<pair<long,long> >v;
  for(long i=n;i>=1;i--)
  {
    if(cnt[i]>mx)
    {
      mx=cnt[i];
      v.push_back({i,cnt[i]});
      //cout<<i<<" "<<cnt[i]<<endl;
    }
  }*/
  vector<pair<long,long> >x;long f=1;
  long now=n;
  while(true)
  {
    if(now%2==0)f=2;
     if(now==4)
    {
      x.push_back({4,cal(4,n)});
      x.push_back({2,cal(2,n)});
      x.push_back({1,cal(1,n)});
      break;
    }
    if(now==2)
    {
      x.push_back({2,cal(2,n)});
      x.push_back({1,cal(1,n)});
      break;      
    }
    if(now==1)
    {
      x.push_back({1,cal(1,n)});
      break;
    }
    x.push_back({now,cal(now,n)});
    x.push_back({now-f,cal(now-f,n)});
     now/=2;
    if(f==2&&now%2)now--;
  }
  //cout<<(x==v)<<endl;
  //for(auto z:x)cout<<z.first<<" "<<z.second<<endl;
  long k;cin>>k;
  for(auto z:x)if(z.second>=k)cout<<z.first<<endl,exit(0);
  return 0;
}