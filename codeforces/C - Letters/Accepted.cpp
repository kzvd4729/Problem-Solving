/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 12:40                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 873 ms                                          memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/978/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,k;
long qm[N+2],x,z;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    qm[i]=x+qm[i-1];
  }
  int p=1;
  for(int i=1;i<=k;i++)
  {
    cin>>z;
    while(true)
    {
      if(z<=qm[p])
      {
        cout<<p<<" "<<z-qm[p-1]<<endl;
        break;
      }
      else p++;
    }
  }
  return 0;
}