/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/04/2020 10:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/734/problem/A
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int a=0,d=0;
  for(auto x:s)
  {
    if(x=='A')a++;else d++;
  }
  if(a>d)cout<<"Anton"<<endl;
  else if(a<d)cout<<"Danik"<<endl;
  else cout<<"Friendship"<<endl;
   return 0;
}