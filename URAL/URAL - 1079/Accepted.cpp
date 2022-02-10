/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 22:15:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 15                                         memory_used (MB): 1.2                             
*  problem: https://vjudge.net/problem/URAL-1079
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100000];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  arr[0]=0;
  arr[1]=1;
  for(long i=2;i<=99999;i++)
  {
    if(i%2==0)
      arr[i]=arr[i/2];
    else arr[i]=arr[i/2]+arr[i/2+1];
  }
  while(cin>>n)
  {
    if(!n)break;
    long mx=0LL;
    for(int i=0;i<=n;i++)
      mx=max(mx,arr[i]);
    cout<<mx<<endl;
  }
  return 0;
}