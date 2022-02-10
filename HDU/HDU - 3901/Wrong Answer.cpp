/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 21:04:06                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-3901
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e5;

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
}hs,tmp;
string s[N+2];bool ok[N+2][12+2],ls;
string a,b;int n,dp[N+2][12+2];
bool dfs(int i,int j)
{
  if(i>n)
  {
    if(ls)return 1;
    return j==a.size();
  }
  if(j==a.size())return 0;
  if(dp[j][i]!=-1)return dp[j][i];
  int ret=dfs(i,j+1);
  if(ok[j][i])ret|=dfs(i+1,j+s[i].size());
  return dp[j][i]=ret;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("opt.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);int t;cin>>t;
  while(t--)
  {
    cin>>a>>b;
    if(a=="0"&&b=="0")break;
    hs.s=a;hs.makeHash();
    n=0;int l=0;b.push_back('*');
    for(int i=0;i<b.size();i++)
    {
      if(b[i]=='*')
      {
        if(i-l)s[++n]=b.substr(l,i-l);
        l=i+1;
      }
    }
    b.pop_back();
    for(int i=1;i<=n;i++)
    {
      vector<pair<int,int> >v;
      s[i].push_back('?');
      int l=0;tmp.s=s[i];tmp.makeHash();
      for(int j=0;j<s[i].size();j++)
      {
        if(s[i][j]=='?')
        {
          v.push_back({l,j-1});
          l=j+1;
        }
      }
      s[i].pop_back();
      for(int j=0;j<a.size();j++)
      {
        if(j+s[i].size()>a.size())continue;
        int p=j,f=1;
        for(auto x:v)
        {
          if(x.second>=x.first)
          {
            if(tmp.segment(x.first,x.second)!=hs.segment(p,p+x.second-x.first))f=0;
            p+=x.second-x.first+1;
          }
          p++;
        }
        ok[j][i]=f;//cout<<j<<" "<<i<<" "<<ok[j][i]<<endl;
        tmp.clear();
      }
    }
    memset(dp,-1,sizeof dp);
    ls=0;
    if(b.back()=='*')ls=1;
    int ans=0;
    if(b[0]=='*')ans=dfs(1,0);
    else if(ok[0][1])ans=dfs(2,s[1].size());
    if(ans)cout<<"YES\n";else cout<<"NO\n";
    memset(ok,0,sizeof ok);

    hs.clear();
  }
  return 0;
}