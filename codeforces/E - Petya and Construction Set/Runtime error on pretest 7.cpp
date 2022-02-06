/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 17:20                        
*  solution_verdict: Runtime error on pretest 7              language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/1214/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<vector<int> >v;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;v.resize(n+1);v[0].resize(3);v[0][0]=1e9;
  for(int i=1;i<=n;i++)
  {
    v[i].resize(3);cin>>v[i][0];
    v[i][1]=i*2,v[i][2]=i*2-1;
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
   for(int i=1;i<=n;i++)
    aa[i]=v[i][1];
   vector<pair<int,int> >ed;
  int mx=n;
  for(int i=1;i<=n;i++)
  {
    if(i>1)ed.push_back({aa[i],aa[i-1]});
     int dw=i+v[i][0];
    if(dw>mx+1)assert(0);
     if(dw>mx)
    {
      mx++;aa[mx]=v[i][2];
      ed.push_back({aa[mx],aa[mx-1]});
    }
    else
    {
      dw--;
      ed.push_back({aa[dw],v[i][2]});
    }
  }
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}