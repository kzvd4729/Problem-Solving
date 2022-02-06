/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 21:09                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1017/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n;
vector<int>hg[N+2];
void divide(int lo,int hi,int h)
{
  if(lo>hi)return ;
  int md=(lo+hi)/2;
  hg[h].push_back(md);
  divide(lo,md-1,h+1);
  divide(md+1,hi,h+1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  divide(1,n,1);
  for(int i=1;i<=N;i++)
  {
    for(auto x:hg[i])
      cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}