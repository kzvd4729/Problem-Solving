/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/19/2020 12:30                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/814/problem/B
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
int a[N+2],b[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
   int x=-1,y=-1;
  for(int i=1;i<=n;i++)
  {
    if(a[i]!=b[i])
    {
      if(x==-1)x=i;else if(y==-1)y=i;
      else assert(0);
    }
    else ans[i]=a[i],st.erase(a[i]);
  }
  if(y==-1)ans[x]=*st.begin();
  else
  {
    int fr=*st.begin(),sc=*st.rbegin();
    if((fr==a[x]||fr==b[x])&&(sc==a[y]||sc==b[y]))
      ans[x]=fr,ans[y]=sc;
    else ans[x]=sc,ans[y]=fr;
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}