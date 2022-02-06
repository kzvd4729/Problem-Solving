/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/19/2021 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1474/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string a;cin>>a;
     int p=-1;
    for(int i=0;i<n;i++)
    {
      if(a[i]=='0')
      {
        if(p==1)
        {
          cout<<0;p=0;
        }
        else
        {
          cout<<1;p=1;
        }
      }
      else
      {
        if(p==2)
        {
          cout<<0;p=1;
        }
        else
        {
          cout<<1;p=2;
        }
      }
    }
    cout<<endl;
  }
    return 0;
}