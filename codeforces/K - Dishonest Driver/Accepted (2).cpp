/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/03/2020 23:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4586 ms                                         memory_used: 9900 KB                              
*  problem: https://codeforces.com/gym/102465/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 //.............................................................
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
}hs;
//............................................................
int dp[702][702];
bool isSame(int l,int r)
{
  for(int i=l+1;i<=r;i++)
    if(hs.s[i]!=hs.s[i-1])return 0;
  return 1;
}
int dfs(int l,int r)
{
  if(l>r)return 0;if(dp[l][r]!=-1)return dp[l][r];
  if(isSame(l,r))return dp[l][r]=1;int now=inf;
  for(int ln=1;ln<=r-l;ln++)
  {
    for(int i=l+ln;i+ln-1<=r;i+=ln)
    {
      if(hs.segment(l,l+ln-1)!=hs.segment(i,i+ln-1))break;
      now=min(now,dfs(l,l+ln-1)+dfs(i+ln,r));
    }
  }
  for(int i=l;i<r;i++)now=min(now,dfs(l,i)+dfs(i+1,r));
  return dp[l][r]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);int n;cin>>n;cin>>hs.s;hs.makeHash();
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,n-1)<<endl;
  return 0;
}