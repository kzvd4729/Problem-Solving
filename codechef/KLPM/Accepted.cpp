/****************************************************************************************
*  @author: kzvd4729                                         created: 09-04-2019 22:17:46                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 26.5M                                
*  problem: https://www.codechef.com/APRIL19A/problems/KLPM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int b1=193,b2=307;
const long m1=1000001011,m2=1000009999;
long pw1[N+2],pw2[N+2];
int rqm[N+2][N+2],fqm[N+2][N+2],dp[N+2][N+2];
void power_cal(void)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=N;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%m1;
    pw2[i]=(pw2[i-1]*b2)%m2;
  }
}
struct _hash
{
  string s;vector<pair<long,long> >v;
  void make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%m1;
      hs2=(hs2*b2+x)%m2;
      v.push_back({hs1,hs2});
    }
  }
  pair<long,long>segment(int l,int r)
  {
    long x=v[r].first,y=v[r].second;
    if(!l)return {x,y};
    x=(x-(v[l-1].first*pw1[r-l+1])%m1+m1)%m1;
    y=(y-(v[l-1].second*pw2[r-l+1])%m2+m2)%m2;
    return {x,y};
  }
}hs,sh;int n;
bool isPal(int l,int r)
{
  if(l>r)return false;
  return (hs.segment(l,r)==sh.segment(n-1-r,n-1-l));
}
string s;
int dfs(int i,int j)
{
  if(i>=j)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  dfs(i+1,j);dfs(i,j-1);
  if(s[i]==s[j])
    return dp[i][j]=1+dfs(i+1,j-1)+fqm[i+1][j-1]+rqm[i+1][j-1];
  return dp[i][j]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  power_cal();cin>>s;hs.s=s,sh.s=s;
  reverse(sh.s.begin(),sh.s.end());
  hs.make_hash();sh.make_hash();
  n=s.size();
  for(int i=n-1;i>=0;i--)
  {
    for(int j=i;j>=0;j--)
    {
      if(isPal(j,i))
        rqm[j][i]++;
    }
    for(int j=i-1;j>=0;j--)
      rqm[j][i]+=rqm[j+1][i];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      if(isPal(i,j))
        fqm[i][j]++;
    }
    for(int j=i+1;j<n;j++)
      fqm[i][j]+=fqm[i][j-1];
  }
  memset(dp,-1,sizeof(dp));
  dfs(0,n-1);long ans=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(dp[i][j]>0)
        ans+=(dp[i][j]*1LL);
  cout<<ans<<endl;
  return 0;
}