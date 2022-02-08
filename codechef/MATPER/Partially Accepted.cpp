/****************************************************************************************
*  @author: kzvd4729                                         created: 05-03-2019 18:49:36                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.97 sec                                        memory_used: 135.9M                               
*  problem: https://www.codechef.com/MARCH19A/problems/MATPER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5+10;
/**************** Hash ******************/
const long mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
long pw1[N+2],pw2[N+2];
void Call(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%mod1;
    pw2[i]=(pw2[i-1]*b2)%mod2;
  }
}
struct Hash
{
  string s;vector<pair<long,long> >v;
  pair<long,long>make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%mod1;
      hs2=(hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<long,long>segment(int lt,int rt)
  {
    long x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=(x-(v[lt-1].first*pw1[rt-lt+1])%mod1+mod1)%mod1;
    y=(y-(v[lt-1].second*pw2[rt-lt+1])%mod2+mod2)%mod2;
    return {x,y};
  }
}Hs[N+2];
/////////////////////////////////////////
int n,k,sz[N+2],nxt[20][N+2];
map<int,long>mp[N+2];
long dfs(int msk,int lst)
{
  if(__builtin_popcount(msk)==k)return 1;
  if(mp[lst].count(msk))return mp[lst][msk];
  long now=0;
  for(int i=0;i<k;i++)
  {
    if(msk&(1<<i))continue;
    if(nxt[i][lst]<n)
      now+=dfs(msk|(1<<i),nxt[i][lst]+sz[i]);
  }
  return mp[lst][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  Call(N);cin>>n>>k;memset(nxt,-1,sizeof(nxt));
  Hash h;cin>>h.s;h.make_hash();
  for(int i=0;i<k;i++)
  {
    Hash hs;cin>>hs.s;sz[i]=hs.s.size();
    pair<long,long>p=hs.make_hash();
    for(int j=0;j<n;j++)
    {
      if(j+hs.s.size()-1>=n)continue;
      if(h.segment(j,j+hs.s.size()-1)==p)
        nxt[i][j]=j;
    }
    nxt[i][n+1]=n+1;
    for(int j=n;j>=0;j--)
      if(nxt[i][j]==-1)nxt[i][j]=nxt[i][j+1];
  }
  /*for(int i=0;i<3;i++)
  {
    for(int j=0;j<=n+1;j++)
    {
      cout<<nxt[i][j]<<" ";
    }
    cout<<endl;
  }*/
  cout<<dfs(0,0)<<endl;
  return 0;
}