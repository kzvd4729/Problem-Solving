/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101972/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int fr[30];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=1;i<=26;i++)
      cin>>fr[i];
    int ln=0,cnt=0,mn=1e9+1;
    for(int i=1;i<=26;i++)
    {
      if(fr[i]>=2)
      {
        fr[i]-=2;ln+=2;
        mn=min(mn,fr[i]/2);
      }
      else if(fr[i])cnt++;
    }
    if(cnt)
    {
      ln++;cnt--;
      cout<<ln<<" "<<1+min(mn,cnt)<<endl;
    }
    else
    {
      if(ln==0)cout<<ln<<" "<<0<<endl;
      else cout<<ln<<" "<<1+mn<<endl;
    }
  }
  return 0;
}