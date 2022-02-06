/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/19/2020 18:54                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/794/problem/C
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
const int N=1e6;
int ca[26+2],cb[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;string c;c.resize(a.size());
  for(auto x:a)ca[x-'a']++;for(auto x:b)cb[x-'a']++;
   for(int j=0;j<a.size();j++)
  {
    int mn,mx;
    for(int i=0;i<26;i++)if(cb[i])mx=i;
    for(int i=25;i>=0;i--)if(ca[i])mn=i;
     if(j%2==0)c[j]=(char)(mn+'a'),ca[mn]--;
    else c[j]=(char)(mx+'a'),cb[mx]--;
  }
  cout<<c<<endl;
  return 0;
}