/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2020 12:36                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1088/problem/D
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a=0,b=0,c=0,d=0,f=2;
  for(int i=29;i>=0;i--)
  {
    if(f==2)
    {
      cout<<"? "<<c<<" "<<d<<endl;
      cin>>f;
    }
    if(f==0)
    {
      cout<<"? "<<(c^(1<<i))<<" "<<d<<endl;
      int x;cin>>x;
      if(x==0)assert(0);
      else if(x==-1)a|=(1<<i),b|=(1<<i);
    }
    else if(f==1)
    {
      cout<<"? "<<(c^(1<<i))<<" "<<(d^(1<<i))<<endl;
      int x;cin>>x;
      if(x==-1)
      {
        a|=(1<<i),c|=(1<<i);f=2;
      }
      else
      {
        cout<<"? "<<(c^(1<<i))<<" "<<d<<endl;
        int x;cin>>x;
        if(x==-1)a|=(1<<i),b|=(1<<i);
      }
    }
    else
    {
      cout<<"? "<<(c^(1<<i))<<" "<<(d^(1<<i))<<endl;
      int x;cin>>x;
      if(x==1)
      {
        b|=(1<<i),d|=(1<<i);f=2;
      }
      else
      {
        cout<<"? "<<(c^(1<<i))<<" "<<d<<endl;
        int x;cin>>x;
        if(x==-1)a|=(1<<i),b|=(1<<i);
      }
    }
  }
  cout<<"! "<<a<<" "<<b<<endl;
  return 0;
}