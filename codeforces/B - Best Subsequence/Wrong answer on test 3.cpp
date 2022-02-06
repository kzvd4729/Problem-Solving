/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2019 20:21                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 90200 KB                             
*  problem: https://codeforces.com/gym/102268/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int sp[N+2][20+2],aa[N+2],n,k;
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=aa[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
bool ok(int md)
{
  vector<pair<int,int> >v;v.push_back({0,0});
  for(int i=1;i<=n;i++)
    if(aa[i]<=md/2)v.push_back({aa[i],i});
  v.push_back({0,n+1});
  int cnt=v.size()-2;
  for(int i=1;i<v.size();i++)
  {
    if(v[i-1].second<v[i].second-1)
    {
      int mn=get(v[i-1].second+1,v[i].second-1);
      if(v[i-1].first+mn<=md&&v[i].first+mn<=md)cnt++;
    }
  }
  return cnt>=k;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   build(n);
  int lo=0,hi=2e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)if(ok(md))break;
  cout<<md<<endl;
   return 0;
}