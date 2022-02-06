/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/30/2018 22:34                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/504/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<pair<int,int> >ed;
vector<int>adj[N+2];
struct data
{
  int dg,xx,id;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.dg<B.dg;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>aa[i].dg>>aa[i].xx;
    aa[i].id=i;
  }
  sort(aa,aa+n,cmp);
  for(int i=0;i<n;i++)
  {
    if(aa[i].dg==adj[aa[i].id].size())continue;
    int xxr=0;
    for(auto x:adj[aa[i].id])
      xxr^=x;
    ed.push_back({aa[i].id,xxr^aa[i].xx});
    adj[aa[i].id].push_back(xxr^aa[i].xx);
    adj[xxr^aa[i].xx].push_back(aa[i].id);
  }
  cout<<ed.size()<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}