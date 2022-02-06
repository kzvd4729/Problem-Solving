/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/27/2020 19:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1282/problem/D
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=3e2;
void ck(int x){if(x==0)exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<'a'<<endl;int x;cin>>x;ck(x);
   int n=x;
   int mx=300;
  for(int i=1;i<=mx;i++)cout<<'a';cout<<endl;
  cin>>x;ck(x);
   if(x==mx)
  {
    for(int i=1;i<=n;i++)cout<<'b';cout<<endl;
    cin>>x;if(x)assert(0);ck(x);
  }
  n++;int ds=x-(mx-n);assert(ds>=0);
   string s;
  for(int i=1;i<=n;i++)s.push_back('a');
   for(int i=0;i<s.size()-1;i++)
  {
    s[i]='b';cout<<s<<endl;cin>>x;ck(x);
    if(x<ds)ds=x;else s[i]='a';
  }
  if(ds)s[n-1]='b';
  cout<<s<<endl;cin>>x;if(x)assert(0);ck(x);ck(x);
  return 0;
}