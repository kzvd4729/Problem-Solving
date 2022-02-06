/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2018 13:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/354/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long dp[20][5],nm[7];
vector<long>lk[10][5];
string s;
void reckon(long st,vector<long>v)
{
  if(st==6)
  {
    long sum=0;
    for(auto x:v)
      sum+=x;
    lk[sum%10][sum/10]=v;
    return ;
  }
  v.push_back(0);reckon(st+1,v);
  v.pop_back();
   v.push_back(4);reckon(st+1,v);
  v.pop_back();
   v.push_back(7);reckon(st+1,v);
  v.pop_back();
}
long dfs(long st,long cr)
{
  if(st==s.size())
  {
    if(cr)return dp[st][cr]=0;
    return dp[st][cr]=1;
  }
  if(dp[st][cr]!=-1)return dp[st][cr];
  long nn=s[st]-'0',rq;
  if(cr>nn)rq=nn+10-cr;
  else rq=nn-cr;long ret=0;
  for(long i=0;i<5;i++)
  {
    if(lk[rq][i].size()==0)continue;
    long sum=cr;
    for(auto x:lk[rq][i])
      sum+=x;
    ret|=dfs(st+1,sum/10);
  }
  return dp[st][cr]=ret;
}
void path(long st,long cr)
{
  if(st==s.size())return ;
  long nn=s[st]-'0',rq;
  if(cr>nn)rq=nn+10-cr;
  else rq=nn-cr;long ret=0;
  for(long i=0;i<5;i++)
  {
    if(lk[rq][i].size()==0)continue;
    long sum=cr;
    for(auto x:lk[rq][i])
      sum+=x;
    if(dp[st+1][sum/10]==1)
    {
      path(st+1,sum/10);
      //cout<<"here"<<endl;
      for(long j=0;j<lk[rq][i].size();j++)
      {
        long x=lk[rq][i][j];
        nm[j]=nm[j]*10+x;
      }
      return ;
    }
  }
  return ;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<long>v;reckon(0,v);
  long q;cin>>q;
  while(q--)
  {
    cin>>s;reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));long f=dfs(0,0);
    if(!f)
    {
      cout<<-1<<endl;
      continue;
    }
    memset(nm,0,sizeof(nm));path(0,0);
    for(long i=0;i<6;i++)
      cout<<nm[i]<<" ";
    cout<<endl;
  }
  return 0;
}