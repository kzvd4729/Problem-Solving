/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2018 13:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1080/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    //(n/2)*(n/2+1) - (m/2)*(m/2+1) 
   long q;cin>>q;
   while(q--)
  {
    long lt,rt;cin>>lt>>rt;
    long all=(rt*(rt+1))/2;
    all-=((lt*(lt-1))/2);
     if(lt%2==0)lt--;
     long ev=(rt/2)*(rt/2+1)-(lt/2)*(lt/2+1);
     //cout<<"*"<<ev<<endl;
     long od=all-ev;
     cout<<ev-od<<endl;
  }
  return 0;
}