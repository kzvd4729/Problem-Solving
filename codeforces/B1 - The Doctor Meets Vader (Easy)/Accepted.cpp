/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 13:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1184/problem/B1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int qm[N+2],atack[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int s,b;cin>>s>>b;
  for(int i=1;i<=s;i++)
    cin>>atack[i];
  for(int i=1;i<=b;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+b+1);
  for(int i=1;i<=b;i++)
    qm[i]=qm[i-1]+pp[i].second;
  for(int i=1;i<=s;i++)
  {
    int id=upper_bound(pp+1,pp+b+1,make_pair(atack[i]+1,-1))-pp;
    cout<<qm[id-1]<<" ";
  }
  cout<<endl;
  return 0;
}