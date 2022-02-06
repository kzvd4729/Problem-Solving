/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 14:44                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/192/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x;
map<long,long>mp;
vector<long>v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=0;  ;i++)
  {
    x=(i*(i+1))/2;
    if(x>n)break;
    mp[x]=1;
    v.push_back(x);
  }
  for(auto x:v)
  {
    if(mp[n-x])
    {
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}