/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2018 22:49                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/959/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt,nn;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  if(n<8)
  {
    n--;
    cout<<-1<<endl;
    cnt=1;
    while(n--)
    {
      cout<<cnt<<" "<<cnt+1<<endl;
      cnt++;
    }
  }
  else
  {
    nn=n;
    nn--;
    cout<<1<<" "<<2<<endl;
    cout<<1<<" "<<3<<endl;
    cout<<2<<" "<<4<<endl;
    cout<<2<<" "<<5<<endl;
    cout<<3<<" "<<6<<endl;
    cout<<4<<" "<<7<<endl;
    cout<<4<<" "<<8<<endl;
    nn-=7;
    cnt=8;
    while(nn--)
    {
      cout<<4<<" "<<++cnt<<endl;
    }
    n--;
    cnt=1;
    while(n--)
    {
      cout<<cnt<<" "<<cnt+1<<endl;
      cnt++;
    }
  }
  return 0;
}