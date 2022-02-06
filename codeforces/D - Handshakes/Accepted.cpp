/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 18:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 7700 KB                              
*  problem: https://codeforces.com/contest/534/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>vv[N+2],ans[3];
void inv(void)
{
  cout<<"Impossible"<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    vv[x].push_back(i);
  }
  int now=0,f=2;
  while(true)
  {
    if(vv[now].size())
    {
      ans[f].push_back(vv[now].back());
      vv[now].pop_back();
      now++;
    }
    else now-=3;
    if(now<0)
    {
      if(f==1)break;
      now=0,f=1;
    }
  }
  if(ans[1].size()+ans[2].size()!=n||(f==1&&now%3))inv();
  cout<<"Possible"<<endl;
  for(auto x:ans[1])cout<<x<<" ";
  for(auto x:ans[2])cout<<x<<" ";
  cout<<endl;
  return 0;
}