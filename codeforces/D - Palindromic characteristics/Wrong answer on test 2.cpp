/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2020 14:24                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 197000 KB                            
*  problem: https://codeforces.com/contest/835/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
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
}a,b;
int n;
inline bool isPal(int i,int j)
{
  return a.segment(i,j)==b.segment(n-1-j,n-1-i);
}
int ans[N+2];
bitset<16+2>dp[5000+2][5000+2];
string get()
{
  string a;
  for(int i=1;i<=5000;i++)
    a.push_back('a');
  return a;
}
int kmp[5000+2][5000+2];
void doKmp(int id,string &s)
{
  int n=s.size();kmp[id][id]=0;
  for(int i=1;i<n;i++)
  {
    int now=kmp[id][id+i-1];
    while(true)
    {
      if(s[now]==s[i]){kmp[id][id+i]=now+1;break;}
      if(!now)break;now=kmp[id][id+now-1];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);cin>>a.s;string s=a.s;
  b.s=a.s;reverse(b.s.begin(),b.s.end());
  a.makeHash();b.makeHash();n=a.s.size();
  for(int i=0;i<n;i++)
  {
    doKmp(i,s);s.erase(s.begin());
  }
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      dp[i][j][0]=isPal(i,j);
      cnt+=dp[i][j][0];
    }
  }
  ans[1]=cnt;
  for(int k=1;k<=16;k++)
  {
    cnt=0;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        int md=(j-i+1)/2;
        if(!(dp[i][i+md-1][k-1]&dp[j-md+1][j][k-1]))continue;
        if(kmp[i][j-md+1]>=md)dp[i][j][k]=1,cnt++;
        //if(a.segment(i,i+md-1)==a.segment(j-md+1,j))dp[i][j][k]=1,cnt++;
      }
    }
    //cout<<k<<" "<<cnt<<endl;
    if(cnt==0)break;ans[k+1]=cnt;
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}