/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/10/2020 16:11                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/549/problem/C
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
const int N=1e6,inf=1e9;
void dan(){cout<<"Daenerys\n",exit(0);}
void stan(){cout<<"Stannis\n",exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int ev=0,od=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(x%2==0)ev++;else od++;
  }
  int mv=n-k;
   if(mv%2==0)//dan has last move
  {
    if(mv/2>=od)dan();//dan removes all odd number
     if(ev<=mv/2)//stan will remove all even number
    {
      od-=(mv-ev);
      if(od%2==0)dan();else stan();
    }
    else dan();
  }
  else
  {
    if(mv/2>=od)dan();//dan removes all odd number
     if(ev<=mv/2)//dan will remove all even number
    {
      od-=(mv-ev);
      if(od%2==0)dan();else stan();
    }
    else
    {
      int f1=0,f2=0;if(mv/2>=od-1)f1=1;
      if(ev-1<=mv/2)
      {
        od-=(mv-ev);
        if(od%2==0)f2=1;
      }
      if(f1&&f2)dan();
      else stan();
    }
  }
  return 0;
}