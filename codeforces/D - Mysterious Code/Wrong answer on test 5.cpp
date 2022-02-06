/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 23:47                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 10600 KB                             
*  problem: https://codeforces.com/contest/1163/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
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
};
string s,a,b;int aa[N+2],bb[N+2];
int dp[1003][52][52];
int dfs(int i,int j,int k)
{
  if(i>=s.size())return 0;
  if(dp[i][j+1][k+1]!=-1)return dp[i][j+1][k+1];
  if(s[i]!='*')
  {
    while(true)
    {
      if(a[j+1]==s[i])
      {
        j++;break;
      }
      if(j==-1)break;
      j=aa[j];
    }
    while(true)
    {
      if(b[k+1]==s[i])
      {
        k++;break;
      }
      if(k==-1)break;
      k=bb[k];
    }
    int cnt=0;
    if(j==a.size()-2)cnt++;
    if(k==b.size()-2)cnt--;
    return dp[i][j+1][k+1]=cnt+dfs(i+1,j,k);
  }
  int now=-1e9,jj=j,kk=k;
  for(char c='a';c<='z';c++)
  {
    j=jj,k=kk;
    while(true)
    {
      if(a[j+1]==c)
      {
        j++;break;
      }
      if(j==-1)break;
      j=aa[j];
    }
    while(true)
    {
      if(b[k+1]==c)
      {
        k++;break;
      }
      if(k==-1)break;
      k=bb[k];
    }
    int cnt=0;
    if(j==a.size()-2)cnt++;
    if(k==b.size()-2)cnt--;
    now=max(now,cnt+dfs(i+1,j,k));
  }
  return dp[i][j+1][k+1]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>a>>b;Call(N);
  Hash hs1,hs2;hs1.s=a;hs2.s=b;
  hs1.make_hash();hs2.make_hash();
  memset(aa,-1,sizeof(aa));
  memset(bb,-1,sizeof(bb));
  for(int i=0;i<a.size();i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      if(hs1.segment(0,j)==hs1.segment(i-j,i))
      {
        aa[i]=j;break;
      }
    }
  }
  for(int i=0;i<b.size();i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      if(hs2.segment(0,j)==hs2.segment(i-j,i))
      {
        bb[i]=j;break;
      }
    }
  }
  a.push_back('#');b.push_back('#');
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,-1,-1)<<endl;
  return 0;
}