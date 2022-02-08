/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:24:09                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,c;cin>>a>>b>>c;
   if(c<=max(a,b))cout<<"No\n",exit(0);
   long lft=4*a*b,rgt=(c-a-b)*(c-a-b);
  //cout<<lft<<" "<<rgt<<endl;
  if(lft<rgt)cout<<"Yes\n";
  else cout<<"No\n";
   return 0;
}