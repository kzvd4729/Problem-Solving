/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2019 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/1260/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],n,t;
vector<vector<int> >tp;
bool ok(int md)
{
  int mn=aa[md];int ret=n+1;
  for(int i=0;i<tp.size();i++)
  {
    if(tp[i][2]<=mn)continue;
    int lo=tp[i][0],hi=tp[i][1];
    while(true)
    {
      i++;if(i==tp.size())break;
      if(tp[i][2]<=mn)continue;
       if(tp[i][0]<=hi)hi=max(hi,tp[i][1]);
      else break;
    }
    ret+=2*(hi-lo+1);i--;
  }
  //cout<<ret<<endl;
  return ret<=t;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>m>>n>>k>>t;
  for(int i=1;i<=m;i++)cin>>aa[i];
  sort(aa+1,aa+m+1,greater<int>());
    tp.resize(k);
  for(int i=0;i<k;i++)
  {
    tp[i].resize(3);
    cin>>tp[i][0]>>tp[i][1]>>tp[i][2];
  }
  sort(tp.begin(),tp.end());
   // ok(3);
  // return 0;
   int lo=1,hi=m,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))break;
  cout<<md<<endl;
  return 0;
}