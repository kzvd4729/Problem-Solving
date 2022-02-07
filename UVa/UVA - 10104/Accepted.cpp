/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-21 00:06:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 100                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10104
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int gcd(int a,int b,int &x,int &y)
{
  if(!b)
  {
    x=1;y=0;
    return a;
  }
  int x1,y1;
  int g=gcd(b,a%b,x1,y1);
  x=y1;y=x1-(a/b)*y1;
  return g;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int a,b,x,y;
  while(cin>>a>>b)
  {
    int g=gcd(a,b,x,y);
    cout<<x<<" "<<y<<" "<<g<<endl;
  }
  return 0;
}