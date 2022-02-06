/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 00:17                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/749/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
double ret(double n){return n*(n-1)/4.0;}
pair<long,long>bit[N+2];
void upd(int id,int vl)
{
  for( ;id>0;id-=id&-id)
    bit[id].first++,bit[id].second+=vl;
}
pair<long,long>get(int id)
{
  pair<long,long>ret;ret={0,0};
  for( ;id<=N;id+=id&-id)
    ret.first+=bit[id].first,ret.second+=bit[id].second;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;double ans=0;
  for(int i=1;i<=n;i++)ans+=ret(i)*(n-i+1);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    pair<long,long>p=get(x);
    //cout<<p.first<<endl;
    ans+=p.first*((n*(n+1))/2)-(p.second*(n-i+1));
    upd(x,i);
  }
  //cout<<setprecision(9)<<fixed<<ans<<endl;
  double d=(n*(n+1))/2;
  ans/=d;cout<<setprecision(9)<<fixed<<ans<<endl;
  return 0;
}