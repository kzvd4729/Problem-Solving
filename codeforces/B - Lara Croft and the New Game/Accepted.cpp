/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2018 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/976/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
  k++;
   if(k<=n)
  {
    cout<<k<<" "<<1<<endl;
    return 0;
  }
  if(k<n+m)
  {
    cout<<n<<" "<<k-n+1<<endl;
    return 0;
  }
   long xx=m-1;
   k-=(n+m-1);
    long koto=(k+xx-1)/xx;
    k-=((koto-1)*xx);
   if(koto%2==1)
  {
    cout<<n-koto<<" "<<m-k+1<<endl;
    return 0;
  }
  else
  {
    cout<<n-koto<<" "<<k+1<<endl;
  }
   return 0;
}