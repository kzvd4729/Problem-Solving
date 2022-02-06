/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 18:54                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/478/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long a,b,c,tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
  long ans=0;
  if(b>a)swap(a,b);
  if(c>a)swap(a,c);
  if(c>b)swap(b,c);
   ans=c;
  a-=c;
  b-=c;
   while(true)
  {
    if(b>a)swap(a,b);
    if(b==0)break;
    if(a-b==1)
    {
      ans++;
      a-=2;
      b--;
      continue;
    }
    if(a==b)
    {
      if(a%3==0||a%3==1)
        ans+=(a/3)*2;
      else if(a%3==2)
        ans+=(1/3)*2+1;
      break;
    }
    tmp=(a-b)/2;
    ans+=tmp;
    a-=(tmp*2);
    b-=tmp;
  }
   cout<<ans<<endl;
  return 0;
}