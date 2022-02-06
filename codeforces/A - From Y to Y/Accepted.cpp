/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 16:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/848/problem/A
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>k;string s;
  for(char c='a';c<='z';c++)
  {
    s.push_back(c);int cnt=1;
    while(true)
    {
      if(cnt>k)break;
      s.push_back(c);k-=cnt;cnt++;
    }
    if(k==0)break;
  }
  cout<<s<<endl;
  return 0;
}