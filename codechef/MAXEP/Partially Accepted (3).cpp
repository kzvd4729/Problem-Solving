/****************************************************************************************
*  @author: kzvd4729                                         created: 09-12-2018 21:36:27                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/DEC18A/problems/MAXEP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void liniar(int lo,int hi)
{
  for(int i=lo;i<=hi;i++)
  {
    cout<<1<<" "<<i<<endl;
    fflush(stdout);
    int x;cin>>x;
    if(x)
    {
      cout<<3<<" "<<i<<endl;
      exit(0);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c;cin>>n>>c;
  int lo=1,hi=n;
  while(hi-lo>900)
  {
    int md=lo+(hi-lo)/6;
    cout<<1<<" "<<md<<endl;
    fflush(stdout);
    int x;cin>>x;
    if(!x)lo=md;
    else 
    {
      cout<<2<<endl;fflush(stdout);
      hi=md;
    }
  }
  liniar(lo,hi);
  return 0;
}