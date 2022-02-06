/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 15:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1303/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    int f=-1,l=-2;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')
      {
        l=i;
        if(f==-1)f=i;
      }
    }
    int cnt=0;
    for(int i=f;i<=l;i++)
      if(s[i]=='0')cnt++;
    cout<<cnt<<endl;
  }
    return 0;
}