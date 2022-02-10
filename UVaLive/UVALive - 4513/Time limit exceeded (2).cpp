/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-17 23:17:34                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4513
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
int pw1[N+2],pw2[N+2];
void init(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(1LL*pw1[i-1]*b1)%mod1;
    pw2[i]=(1LL*pw2[i-1]*b2)%mod2;
  }
}
struct hsh
{
  string s;vector<pair<int,int> >v;
  pair<int,int>makehsh(void)
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
  void clear(void)
  {
    v.clear();
  }
};
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init(N);hsh hs;int m;
  while(cin>>m)
  {
    if(!m)break;cin>>hs.s;hs.makehsh();
    int n=hs.s.size();int lo=1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;mp.clear();
      for(int i=0;i+md-1<n;i++)
        mp[{hs.segment(i,i+md-1)}]++;
      int mx=0;
      for(auto it:mp)
        mx=max(mx,it.second);

      if(mx>=m)lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)
    {
      mp.clear();
      for(int i=0;i+md-1<n;i++)
        mp[{hs.segment(i,i+md-1)}]++;
      int mx=0;
      for(auto it:mp)
        mx=max(mx,it.second);
      if(mx>=m)break;
    }
    if(md==0)
    {
      cout<<"none\n";
    }
    else
    {
      cout<<md<<" ";
      mp.clear();int rgt;
      for(int i=0;i+md-1<n;i++)
      {
        int cnt=mp[{hs.segment(i,i+md-1)}]++;
        cnt++;if(cnt>=m)rgt=i;
      }
      cout<<rgt<<"\n";
    }
    hs.clear();
  }
  return 0;
}