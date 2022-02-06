/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 23:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1178/problem/E
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s,x,y;cin>>s;int a=0,b=s.size()-1;
  while(a+1<b-1)
  {
    if(s[a]==s[b])x.push_back(s[a]),a++,b--;
    else if(s[a]==s[b-1])x.push_back(s[a]),a++,b-=2;
    else if(s[a+1]==s[b])x.push_back(s[a+1]),a+=2,b--;
    else if(s[a+1]==s[b-1])x.push_back(s[a+1]),a+=2,b-=2;
    else assert(0);
  }
  y=x;reverse(y.begin(),y.end());
  if(a<=b)x.push_back(s[a]);cout<<x+y<<endl;
  return 0;
}