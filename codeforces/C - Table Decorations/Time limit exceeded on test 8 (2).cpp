/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 18:27                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/478/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long a,b,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
  long ans=0;
  while(true)
  {
    if(b>a)swap(a,b);
    if(c>a)swap(a,c);
    if(c>b)swap(b,c);
    if(b==0)break;
    if((a+b+c)/3==c)
    {
      ans+=c;
      break;
    }
    long tmp;
    if(b==c)
    {
      tmp=min(b,(a-b)/4);
      b-=tmp;
      c-=tmp;
      a-=tmp*4;
      ans+=2*tmp;
      continue;
    }
    tmp=min(b-c,(a-c)/2);
    ans+=tmp;
    b-=tmp;
    a-=(tmp*2);
    //cout<<a<<" "<<b<<" "<<c<<endl;
  }
  cout<<ans<<endl;
  return 0;
}