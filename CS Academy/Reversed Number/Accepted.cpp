/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 8 ms                                            memory_used: 656 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define log long long
using namespace std;
long n,nn,r;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  nn=n;
  long sum=0;
  while(n)
  {
    r=n%10;
    sum=sum*10+r;
    n/=10;
  }
  if(nn<sum)cout<<1<<endl;
  else cout<<0<<endl;
  return 0;
}