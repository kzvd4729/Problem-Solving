/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-15 22:36:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-FCTRL2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s[102],tmp,ans;
int c,n,r,t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  s[1]="1";
  for(int i=2;i<=100;i++)
  {
    ans.clear();
    tmp=s[i-1];
    c=0;
    for(auto x:tmp)
    {
      n=x-'0';
      n*=i;
      n+=c;
      c=n/10;
      n%=10;
      ans.push_back(n+'0');
    }
    while(c)
    {
      r=c%10;
      ans.push_back(r+'0');
      c/=10;
    }
    s[i]=ans;
  }
  for(int i=1;i<=100;i++)reverse(s[i].begin(),s[i].end());
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<s[n]<<endl;
  }
  return 0;
}