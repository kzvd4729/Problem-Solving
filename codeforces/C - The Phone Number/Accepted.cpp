/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 22:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1017/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,sq,arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;sq=sqrt(n);
  int st=n,now=0,id;
  while(true)
  {
    st-=sq;id=max(0,st);
    for(int i=1;i<=sq;i++)
    {
      arr[++id]=++now;
      if(now==n)
      {
         for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
          cout<<endl;
        return 0;
      }
    }
  }
  return 0;
}