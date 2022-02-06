/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1461/problem/A
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
const int N=1e6;
char ch[4];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  ch[0]='b',ch[1]='c',ch[2]='a';
  while(t--)
  {
    int n,k;cin>>n>>k;
    string s;
    for(int i=1;i<=k;i++)s.push_back('a');
     int id=0;
    for(int i=k+1;i<=n;i++)
    {
      s.push_back(ch[id]);
      id++;if(id==3)id=0;
    }
    cout<<s<<endl;
  }
  return 0;
}