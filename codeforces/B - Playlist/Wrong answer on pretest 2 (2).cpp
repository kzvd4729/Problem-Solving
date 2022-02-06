/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2021 21:09                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/1483/problem/B
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
const long N=3e5,inf=1e9,mod=1e9+7;
 long a[N+2],lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(long i=1;i<=n;i++)cin>>a[i];
     for(long i=1;i<n;i++)rt[i]=i+1;
    rt[n]=1;
     for(long i=2;i<=n;i++)lt[i]=i-1;
    lt[1]=n;
     long rm=n;
     set<vector<long> >st;
    map<pair<long,long>,long>mp;
    for(long i=1;i<n;i++)
    {
      if(__gcd(a[i],a[i+1])==1)
      {
        st.insert({i,i,i+1});
        mp[{i,i+1}]=i;
      }
    }
    if(__gcd(a[1],a[n])==1)st.insert({n,n,1});
      vector<long>ans;
    while(st.size())
    {
      //cout<<endl<<endl;
      //for(auto x:st)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
              if(rm==0)break;
      vector<long>v=*st.begin();st.erase(v);
      rm--;ans.push_back(v[2]);
       if(mp.count({v[2],rt[v[2]]}))
      {
        if(st.find({mp[{v[2],rt[v[2]]}],v[2],rt[v[2]]})!=st.end())
        {
          st.erase({mp[{v[2],rt[v[2]]}],v[2],rt[v[2]]});
        }
      }
       if(__gcd(a[v[1]],a[rt[v[2]]])==1)
      {
        st.insert({v[0]+n,v[1],rt[v[2]]});
        mp[{v[1],rt[v[2]]}]=v[0]+n;
      }
       long r=rt[v[2]],l=lt[v[2]];
      rt[l]=r;lt[r]=l;
    }
    cout<<ans.size()<<' ';
    for(auto x:ans)cout<<x<<" ";cout<<'\n';
  }
  return 0;
}