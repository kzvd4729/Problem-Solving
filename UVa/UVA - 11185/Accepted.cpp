/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 20:09:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11185
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(n<0)break;
    vector<int>v;
    while(n)
    {
      v.push_back(n%3);
      n/=3;
    }
    if(v.size()==0)v.push_back(0);
    for(int i=v.size()-1;i>=0;i--)
      cout<<v[i];
    cout<<"\n";
  }
  return 0;
}