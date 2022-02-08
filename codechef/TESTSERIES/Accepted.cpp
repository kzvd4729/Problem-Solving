/****************************************************************************************
*  @author: kzvd4729                                         created: 19-10-2021 12:29:31                      
*  solution_verdict: Accepted                                language: C++17                                   
*  run_time: 0.01 sec                                        memory_used: 5.3M                                 
*  problem: https://www.codechef.com/SNCKQL21/problems/TESTSERIES
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int f=0;
    for(int i=1;i<=5;i++)
    {
      int a;cin>>a;
      if(a==1)f++;
      else if(a==2)f--;
    }
    if(f>0)cout<<"INDIA"<<endl;
    else if(f<0)cout<<"ENGLAND"<<endl;
    else cout<<"DRAW"<<endl;
  }
    return 0;
}