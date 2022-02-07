/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 21:17:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12043
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long dd[N+2],sm[N+2];
void abc(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      dd[j]++;sm[j]+=(i*1LL);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  abc();int t;cin>>t;
  while(t--)
  {
    int a,b,k;cin>>a>>b>>k;
    long aa=0,bb=0;
    for(int i=k;i<=b;i+=k)
    {
      if(i>=a)
        aa+=dd[i],bb+=sm[i];
    }
    cout<<aa<<" "<<bb<<endl;
  }
  return 0;
}