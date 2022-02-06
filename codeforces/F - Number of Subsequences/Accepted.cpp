/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/28/2020 15:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1426/problem/F
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
const int N=1e6,mod=1e9+7;
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
   int a=0,ab=0,abc=0;int p=1;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='a')
    {
      a=(a+p)%mod;
    }
    else if(s[i]=='b')
    {
      ab=(ab+a)%mod;
    }
    else if(s[i]=='c')
    {
      abc=(abc+ab)%mod;
    }
    else
    {
      int tabc=0,tab=0,ta=0;
       int tmpabc=abc,tmpab=ab,tmpa=a;
      tmpa=(tmpa+p)%mod;
       tabc=(tabc+tmpabc)%mod;
      tab=(tab+tmpab)%mod;
      ta=(ta+tmpa)%mod;
        tmpabc=abc,tmpab=ab,tmpa=a;
      tmpab=(tmpab+tmpa)%mod;
       tabc=(tabc+tmpabc)%mod;
      tab=(tab+tmpab)%mod;
      ta=(ta+tmpa)%mod;
        tmpabc=abc,tmpab=ab,tmpa=a;
      tmpabc=(tmpabc+tmpab)%mod;
       tabc=(tabc+tmpabc)%mod;
      tab=(tab+tmpab)%mod;
      ta=(ta+tmpa)%mod;
       abc=tabc,ab=tab,a=ta;
       p=(p*3LL)%mod;
    }
  }
  cout<<abc<<endl;
  return 0;
}