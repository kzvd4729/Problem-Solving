/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 12:08                        
*  solution_verdict: Wrong answer on test 44                 language: GNU C++14                               
*  run_time: 842 ms                                          memory_used: 31200 KB                             
*  problem: https://codeforces.com/contest/576/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,sq=1e3;
vector<int>seg[N+2];
pair<int,pair<int,int> >p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>p[i].first>>p[i].second.first;
    p[i].second.second=i;
  }
  sort(p+1,p+n+1);
  for(int i=1;i<=n;i++)
    seg[p[i].second.first/sq].push_back(p[i].second.second);
  for(int i=0;i<=N;i++)
    for(auto x:seg[i])
      cout<<x<<" ";
  cout<<endl;
  return 0;
}