/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 20:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1111/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool ok(char a)
{
  if(a=='a')return true;
  if(a=='e')return true;
  if(a=='i')return true;
  if(a=='o')return true;
  if(a=='u')return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  if(a.size()!=b.size())cout<<"No"<<endl,exit(0);
  for(int ii=0;ii<a.size();ii++)
  {
    bool i=ok(a[ii]);
    bool j=ok(b[ii]);
    if(i!=j)cout<<"No"<<endl,exit(0);
  }
  cout<<"Yes"<<endl;
  return 0;
}