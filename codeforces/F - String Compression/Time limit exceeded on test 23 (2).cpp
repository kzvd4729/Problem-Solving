/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2019 21:22                        
*  solution_verdict: Time limit exceeded on test 23          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 250900 KB                            
*  problem: https://codeforces.com/contest/825/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=8e3;
const int mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
int pw1[N+2],pw2[N+2];
void cal(int n)
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
  pair<int,int>makeHash(void)
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
}hs;
int dp[N+2],dg[N+2],cnt[N+2][N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);cin>>hs.s;int n=hs.s.size();hs.makeHash();
  for(int i=1;i<10;i++)dg[i]=1;
  for(int i=10;i<100;i++)dg[i]=2;
  for(int i=100;i<1000;i++)dg[i]=3;
  for(int i=1000;i<=N;i++)dg[i]=4;
   for(int i=n-1;i>=0;i--)
  {
    dp[i]=n-i+1;memset(vis,0,sizeof(vis));
    for(int j=i;j<n;j++)
    {
      int d=j-i+1,cnt=1;dp[i]=min(dp[i],1+d+dp[j+1]);
      if(vis[d])continue;pair<int,int>p=hs.segment(i,j);
      for(int k=j+d;k<n;k+=d)
      {
        if(p==hs.segment(k-d+1,k))
        {
          cnt++;vis[d+d]=1;
          dp[i]=min(dp[i],dg[cnt]+d+dp[k+1]);
        }
        else break;
      }
    }
    //cout<<i<<" -- > "<<dp[i]<<endl;
  }
  cout<<dp[0]<<endl;
  return 0;
}