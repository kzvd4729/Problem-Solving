/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2018 00:47                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/987/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
   if(a==b)
  {
    cout<<"="<<endl;
    return 0;
  }
  if(a==1)
  {
    cout<<"<"<<endl;
    return 0;
  }
  if(b==1)
  {
    cout<<">"<<endl;
    return 0;
  }
  if(a<10&&b<10)
  {
    long aa=1;
    for(long i=1;i<=b;i++)
      aa=aa*a;
    long bb=1;
    for(long i=1;i<=a;i++)
      bb=bb*b;
    if(aa==bb)cout<<"="<<endl;
    else if(aa>bb)cout<<">"<<endl;
    else cout<<"<"<<endl;
    return 0;
  }
  else
  {
    if(b>a)cout<<">"<<endl;
    else cout<<"<"<<endl;
    return 0;
  }
   return 0;
}