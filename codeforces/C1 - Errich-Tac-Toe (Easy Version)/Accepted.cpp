/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2020 22:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1450/problem/C1
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
const int N=300;
int n;
string s[N+2],tmp[N+2];
int tryCatch(vector<int>v)
{
  int ret=0;
  for(int i=0;i<n;i++)
  {
    tmp[i]=s[i];
    for(int j=v[i%3];j<n;j+=3)
    {
      if(tmp[i][j]=='X')ret++,tmp[i][j]='O';
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
     vector<int>v;
    for(int i=0;i<3;i++)v.push_back(i);
     int cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cnt+=(s[i][j]=='X');
        cnt/=3;int f=0;
    do
    {
      if(tryCatch(v)<=cnt)
      {
        for(int i=0;i<n;i++)cout<<tmp[i]<<'\n';
        f=1;break;
      }
    }while(next_permutation(v.begin(),v.end()));
    assert(f);
  } 
  return 0;
}