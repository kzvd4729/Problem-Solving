/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 21:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1352/problem/G
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
const int N=8000;
int aa[N+2];
bitset<N+2>vs;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;set<int>st;
    if(n<=3)
    {
      cout<<-1<<'\n';continue;
    }
    if(n==4)
    {
      cout<<"3 1 4 2\n";continue;
    }
    for(int i=2;i<=n;i+=2)st.insert(i);
     for(int i=1;i<=n;i+=2)cout<<i<<" ";
    int ls=n;if(ls%2==0)ls--;
    cout<<ls-3<<" ";st.erase(ls-3);
    while(st.size())
    {
      cout<<*st.rbegin()<<" ";
      st.erase(*st.rbegin());
    }
    cout<<"\n";
  }
  return 0;
}