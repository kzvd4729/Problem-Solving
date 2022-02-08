/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-14 18:49:55                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 199 ms                                          memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc026/tasks/agc026_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,a,b,c,d,tmp;
void no(void)
{
  cout<<"No"<<endl;
}
void ya(void)
{
  cout<<"Yes"<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>t;
  while(t--)
  {
    cin>>a>>b>>c>>d;
     int n=1e5,f=0;
    while(n--)
    {
      tmp=(a-c)-1;
      tmp=max(tmp,0LL);
      a-=(b*(tmp/b));
      a-=b;
      if(a<0)
      {
        no();
        f=1;
        break;
      }
      a+=d;
//      cout<<a<<endl;
//      getchar();
    }
    if(f==0)ya();
  }
  return 0;
}