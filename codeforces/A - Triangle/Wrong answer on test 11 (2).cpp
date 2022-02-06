/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 19:16                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/407/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dis(pair<int,int>p1,pair<int,int>p2)
{
  int a=(p1.first-p2.first);a*=a;
  int b=(p1.second-p2.second);b*=b;
  return a+b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  int aa=a*a,bb=b*b;
  vector<pair<int,int> >u,v;
  for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=1000;j++)
    {
      if(i*i+j*j==aa)
      {
        u.push_back({i,j});
        u.push_back({-i,j});
        u.push_back({i,-j});
        u.push_back({-i,-j});
      }
    }
  }
  for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=1000;j++)
    {
      if(i*i+j*j==bb)
      {
        v.push_back({i,j});
        v.push_back({-i,j});
        v.push_back({i,-j});
        v.push_back({-i,-j});
      }
    }
  }
  for(auto x:u)
  {
    for(auto y:v)
    {
      if(dis(x,y)==aa+bb)
      {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<x.first<<" "<<x.second<<endl;
        cout<<y.first<<" "<<y.second<<endl;
        exit(0);
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}