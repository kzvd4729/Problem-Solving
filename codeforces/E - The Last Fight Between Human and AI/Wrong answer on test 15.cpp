/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2020 12:22                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/676/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int stringToNum(string s)
{
  int in=0;if(s[0]=='-')in=1;
  int ret=0;
  for(int i=in;i<s.size();i++)
    ret=ret*10+s[i]-'0';
  if(s[0]=='-')ret*=-1;
  return ret;
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int f=0;
  for(int i=0;i<=n;i++)
  {
    string s;cin>>s;if(s=="?"){f=1;break;}
    aa[i]=stringToNum(s);
  }
  if(f)
  {
    if(n%2)cout<<"Yes\n";else cout<<"No\n";exit(0);
  }
  long ex=0;
  for(int i=n;i>0;i--)
  {
    long rm=aa[i]-ex;
    ex=rm*(-k);
  }
  if(ex==aa[0])cout<<"Yes\n";else cout<<"No\n";
  return 0;
}