/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 900 KB                               
*  problem: https://codeforces.com/contest/1157/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int con[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  for(int i=1;i<=9;i++)cin>>con[i];
  int f=0;
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'0';
    if(con[c]>c)
    {
      s[i]=(char)(con[c]+'0');
      f=1;
    }
    else if(con[c]<c&&f)break;
  }
  cout<<s<<endl;
  return 0;
}