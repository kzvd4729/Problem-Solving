/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 23:24                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 139300 KB                            
*  problem: https://codeforces.com/contest/1154/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
vector<int>id[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=1e14;int a=-1,b=-1;
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;
    id[x].push_back(i);
    if(id[x].size()>1)
    {
      if(x<ans)
      {
        ans=x;a=id[x][0];b=id[x][1];
      }
    }
  }
  vector<int>v;
  for(int i=1;i<=N;i++)
  {
    if(id[i].size()>0)
      v.push_back(i);
  }
  int r=min(1000,(int)v.size());
  for(int i=0;i<r;i++)
  {
    int r2=v.size();
    if(i>70)r2=r;
    for(int j=i+1;j<r2;j++)
    {
      long ml=(v[i]*1LL)*v[j];
      long gc=__gcd(v[i],v[j]);
      ml/=gc;
      if(ml<ans)
      {
        ans=ml;a=id[v[i]][0];b=id[v[j]][0];
      }
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}