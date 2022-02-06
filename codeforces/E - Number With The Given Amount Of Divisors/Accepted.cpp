/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2019 18:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/27/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int prime[]={2,3,5,7,11,13,17,19,23,29};
long nm=1000000000000000000LL,ans;
int n;vector<int>v;
bool ck(int x)
{
  for(int i=2;i<x;i++)
    if(x%i==0)return false;
  return true;
}
int dd(int x)
{
  for(int i=2;i<=x;i++)
    if(x%i==0&&ck(i))v.push_back(i);
}
void dfs(int st,int x,vector<int>b)
{
  if(x>n)return ;
  if(st==v.size())
  {
    if(x!=n)return ;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    long now=1;int pt=0;
    for(auto x:b)
    {
      x--;
      while(x--)
      {
        now*=prime[pt];
        if(now>nm)return ;
      }
      pt++;
    }
    ans=min(ans,now);
    return ;
  }
  dfs(st+1,x,b);int ml=1;
  for(int i=1;  ;i++)
  {
    ml*=v[st];if(ml*x>n)break;
    vector<int>a=b;a.push_back(ml);
    dfs(st,x*ml,a);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;dd(n);ans=nm;
  vector<int>a;dfs(0,1,a);
  cout<<ans<<endl;
  return 0;
}