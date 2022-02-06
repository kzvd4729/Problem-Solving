/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/05/2019 20:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1217/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int n=s.size(),cnt=0,ans=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='0'){cnt++;continue;}
      int nm=0;
      for(int j=i;j<s.size();j++)
      {
        nm=nm*2+s[j]-'0';
        if(nm>=j-i+1&&nm<=j-i+1+cnt)ans++;
        if(nm>n)break;
      }
      cnt=0;
    }
    cout<<ans<<"\n";
  }
  return 0;
}