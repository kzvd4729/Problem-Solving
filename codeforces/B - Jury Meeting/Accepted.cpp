/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2019 18:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 18400 KB                             
*  problem: https://codeforces.com/contest/853/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e12+1;
long mn[N+2],rem[N+2];
struct data
{
  int day,city,cost;
};
bool cmp(data A,data B)
{
  return A.day<B.day;
}
vector<data>aa,bb;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(c==0)bb.push_back({a,b,d});
    else aa.push_back({a,c,d});
  }
  sort(aa.begin(),aa.end(),cmp);
  sort(bb.begin(),bb.end(),cmp);
  for(int i=1;i<=n;i++)mn[i]=inf;
  long now=(n*1LL)*inf;int pt=aa.size()-1;
  for(int i=N;i>=1;i--)
  {
    rem[i]=now;if(pt<0)continue;
    int f=0;
    if(i==aa[pt].day)
    {
      int d=aa[pt].city;
      now-=mn[d];mn[d]=min(mn[d],aa[pt].cost*1LL);
      now+=mn[d];pt--;f=1;
    }
    rem[i]=now;if(f)i++;
  }
  for(int i=1;i<=n;i++)mn[i]=inf;
  now=(n*1LL)*inf;pt=0;long ans=2e18;
  for(int i=1;i<=N;i++)
  {
    int f=0;
    if(pt<bb.size())
    {
      if(i==bb[pt].day)
      {
        int d=bb[pt].city;
        now-=mn[d];mn[d]=min(mn[d],bb[pt].cost*1LL);
        now+=mn[d];pt++;f=1;
      }
    }
    if(i+k+1<=N)ans=min(ans,now+rem[i+k+1]);
    if(f)i--;
  }
  if(ans>2e11)ans=-1;cout<<ans<<endl;
  return 0;
}