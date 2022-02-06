/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/07/2018 22:11                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/960/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,c;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='a')
    {
      a++;
      if(b||c)
      {
        cout<<"NO"<<endl;
        return 0;
      }
    }
    else if(s[i]=='b')
    {
      b++;
      if(!a||c)
      {
        cout<<"NO"<<endl;
        return 0;
      }
    }
    else
    {
      c++;
      if(!a||!b)
      {
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  if(c!=a&&c!=b)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}