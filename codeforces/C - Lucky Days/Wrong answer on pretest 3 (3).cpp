/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2018 23:01                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1055/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long la,ra,ta;cin>>la>>ra>>ta;
  long lb,rb,tb;cin>>lb>>rb>>tb;
  long a=ra-la+1,b=(la+ta-1)-(ra+1)+1;
  long c=rb-lb+1,d=(lb+tb-1)-(rb+1)+1;
  long df=abs(la-lb);
  long gcd=__gcd(a+b,c+d);
  df%=gcd;
  long a1=max(0LL,min(c-df,a));
  swap(a,c);swap(b,d);
  long b1=max(0LL,min(a-df,c));
  swap(a,c);swap(b,d);
  df=a+b-df;
  long a2=max(0LL,min(c-df,a));
  swap(a,c);swap(b,d);
  long b2=max(0LL,min(a-df,c));
   cout<<max(max(a1,a2),max(b1,b2))<<endl;
  return 0;
}