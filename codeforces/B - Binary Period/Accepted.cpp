/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 10:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1342/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    int z=0,o=0;
    for(auto x:s)
    {
      if(x=='0')z=1;
      else o=1;
    }
    if(!(o&z))cout<<s<<endl;
    else
    {
      for(int i=0;i<s.size();i++)cout<<"01";
        cout<<endl;
    }
  }
    return 0;
}