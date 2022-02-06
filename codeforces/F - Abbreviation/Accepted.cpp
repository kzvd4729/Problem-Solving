/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2020 19:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 37900 KB                             
*  problem: https://codeforces.com/contest/1003/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<random>
#define long long long
using namespace std;
const int N=1e6;
 const int mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;//greater than maximum value
int pw1[N+2],pw2[N+2];
void calPower()
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=N;i++)
  {
    pw1[i]=(1LL*pw1[i-1]*b1)%mod1;
    pw2[i]=(1LL*pw2[i-1]*b2)%mod2;
  }
}
struct hsh
{
  vector<pair<int,int> >v;string s;
  void init(string _s)
  {
    v.clear();s=_s;
  }
  pair<int,int>makeHash()
  {
    int hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(1LL*hs1*b1+x)%mod1;
      hs2=(1LL*hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<int,int>segment(int lt,int rt)
  {
    int x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=x-(1LL*v[lt-1].first*pw1[rt-lt+1])%mod1;
    y=y-(1LL*v[lt-1].second*pw2[rt-lt+1])%mod2;
    if(x<0)x+=mod1;if(y<0)y+=mod2;
    return {x,y};
  }
}hs;
 string tx[N+2];int bg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calPower();string s;
  int n;cin>>n;int tt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>tx[i];tt+=tx[i].size();bg[i]=s.size();
    for(auto x:tx[i])s.push_back(x);
    s.push_back('#');
  }
  tt+=n-1;hs.init(s);hs.makeHash();
  int ans=tt;
  for(int i=1;i<=n;i++)
  {
    int sz=0;
    for(int j=i;j<=n;j++)
    {
      sz+=tx[j].size()+1;
      pair<int,int>mt=hs.segment(bg[i],bg[i]+sz-1);
       int cnt=0;
      for(int k=j+1;k<=n;k++)
      {
        if(bg[k]+sz-1<s.size()&&hs.segment(bg[k],bg[k]+sz-1)==mt)cnt++,k+=j-i;
      }
      //cout<<cnt<<" "<<sz<<" "<<j-i+1<<endl;
      if(cnt)ans=min(ans,tt-(sz-(j-i+1)*2+(j-i))*(cnt+1));
    }
  }
  cout<<ans<<endl;
  return 0;
}