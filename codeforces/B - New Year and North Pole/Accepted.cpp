/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2019 16:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/750/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void no(void){cout<<"NO"<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int dis=0,n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string a;int b;cin>>b>>a;
    if(a=="South")
    {
      dis+=b;if(dis>20000)no();
    }
    else if(a=="East")
    {
      if(dis==0||dis==20000)no();
    }
    else if(a=="West")
    {
      if(dis==0||dis==20000)no();
    }
    else
    {
      dis-=b;if(dis<0)no();
    }
  }
  if(dis!=0)no();cout<<"YES"<<endl;
  return 0;
}