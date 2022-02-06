/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 20:45                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1344/problem/A
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;set<int>st;
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;st.insert((x+i)%n);
    }
    if(st.size()==n)cout<<"YES\n";
    else cout<<"NO\n";
  }
    return 0;
}