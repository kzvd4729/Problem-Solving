/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2020 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1427/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int psm=0,nsm=0;
    vector<int>ps,ng,zr;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(x>0)ps.push_back(x),psm+=x;
      else if(x<0)ng.push_back(x),nsm+=x;
      else zr.push_back(0);
    }
    if(psm+nsm==0)cout<<"NO\n";
    else
    {
      cout<<"YES\n";
      if(psm>-nsm)
      {
        for(auto x:ps)cout<<x<<" ";
        for(auto x:ng)cout<<x<<" ";
      }
      else
      {
        for(auto x:ng)cout<<x<<" ";
        for(auto x:ps)cout<<x<<" "; 
      }
      for(auto x:zr)cout<<x<<" ";
      cout<<'\n';
    }
  }
  return 0;
}