/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/29/2018 23:01                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/622/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;scanf("%d:%d",&a,&b);
   int tim=a*60+b;
  int x;cin>>x;tim+=x;
  tim%=1440;
  int h=tim/60,m=tim%60;
   if(h<10)
    cout<<"0"<<h<<":";
  else cout<<h<<":";
  if(h<10)
    cout<<"0"<<m<<endl;
  else cout<<m<<endl;
   return 0;
}